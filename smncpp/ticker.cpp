#include "ticker.h"
#include "lockm.h"
#include <thread>
#include <iostream>
using namespace std;
namespace smnet{
	typedef SMLockMgr lockm;
	void Ticker::close(){
		_droped = true;
	}

	void Ticker::tick(){
		lockm _(this->_tsafe);
		_chan.one_thread_get();
	}

	void Ticker::put(){
		cout << "ticker: " <<_idx << "\t\tput" <<endl;
		if (_chan.size() > 180){
			return ;
		}

		_chan.push(0);
	}
	
	void TickUnit::tick(){
		++_cur;
		if(_cur < _waitTime){
			return;
		}
		_cur = 0;
		for (auto it = _ticks.begin(); it != _ticks.end(); ){
			auto& cur = *it;
			if(cur->_droped || cur.use_count() == 1){
				_ticks.erase(it++);
				continue;
			}

			cur->put();
			++it;
		}
	}
	

	std::shared_ptr<Ticker> TickUnit::getTicker(){
		std::shared_ptr<Ticker> res(new Ticker());
		this->_ticks.push_back(res);
		return res;
	}

	TickManager::TickManager(){
		_emptyLock.lock();
	}


	TickManager* TickManager::Instance(){
		static TickManager* ins = new TickManager();
		new std::thread(&TickManager::tickLoop, ins);
		return ins;
	}

	void TickManager::tickLoop(){
		while(true){
			bool isEmpty = false;
			{
				lockm _(this->_tsafe);
				if (this->_tunits.empty()){
					isEmpty = true;
				}
			}
			if (isEmpty){
				this->_emptyLock.lock();
			}

			std::this_thread::sleep_for(std::chrono::milliseconds(1));
			for(auto it = this->_tunits.begin(); it != this->_tunits.end();){
				auto& cur = it->second;
	
				{//delete no-use TickUnit;
					lockm _(_tsafe);
					if (cur->empty()){
						_tunits.erase(it++);
						continue;
					}
				}

				{//do tick
					lockm _(_tsafe);
					cur->tick();
				}
				++it;
			}

		}
	}


	std::shared_ptr<Ticker> TickManager::getTicker(int tickMs){
		lockm _(_tsafe);
		bool isEmpty = this->_tunits.empty();
		auto res = _get_ticker(tickMs);
		if(isEmpty && res != nullptr){
			_emptyLock.unlock();
			return res;
		} 

		return res;
	}

	std::shared_ptr<Ticker> TickManager::_get_ticker(int tickMs){
		if (tickMs == 0){
			return nullptr;
		}

		auto ptr = this->_tunits.find(tickMs);
		if (ptr == this->_tunits.end()){
			auto tu =  std::make_shared<TickUnit>(tickMs);
			_tunits[tickMs] = tu;
			return tu->getTicker();
		}

		return ptr->second->getTicker();
	}
}
