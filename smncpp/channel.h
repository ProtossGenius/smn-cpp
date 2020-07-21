#ifndef CHANNEL_H_IZJI8D3M
#define CHANNEL_H_IZJI8D3M

#include <queue>
#include <boost/thread/mutex.hpp>
#include <mutex>

namespace smnet{
	template<typename Type>
	class channel {
		public:
			channel(size_t maxSize = 0):_MAX_SIZE(maxSize){
				if(_MAX_SIZE == 0){
					canNotWriteIn();
				}else{
					queueEmpty();
				}
			}

		public:
			void push(const Type& val){
				bool noSpace = false;
				{
					boost::mutex::scoped_lock _(_tsafe);
					if (_MAX_SIZE == 0 || _quu.size() == _MAX_SIZE - 1){
						noSpace = true;
					}
					if(_MAX_SIZE != 0 && _quu.empty()){
						queueNotEmpty(); //because will push one value.
					}
					_quu.push(val);

				}

				if(noSpace){
					canNotWriteIn();
				}
			}

			void emplace(Type&& val){
				bool noSpace = false;
				{
					boost::mutex::scoped_lock _(_tsafe);
					if (_MAX_SIZE == 0 || _quu.size() == _MAX_SIZE - 1){
						noSpace = true;
					}
					if(_MAX_SIZE != 0 && _quu.empty()){
						queueNotEmpty(); //because will push one value.
					}
					_quu.emplace(val);

				}

				if(noSpace){
					canNotWriteIn();
				}

			}

			bool empty(){
				boost::mutex::scoped_lock _(_tsafe);
				return _quu.empty();
			}

			size_t size(){
				boost::mutex::scoped_lock _(_tsafe);
				return _quu.size();
			}

			//one_thread_get should only call from one thread. it's not thread-safe. or willcaused dead lock.
			Type one_thread_get(){
				bool isQueueEmpty = false;
				{//check if need Lock;
					boost::mutex::scoped_lock _(_tsafe);
					if(_MAX_SIZE == 0 || _quu.size() == _MAX_SIZE-1){
						canWriteIn();
					}
					if (_MAX_SIZE != 0 && _quu.empty()){
						isQueueEmpty = true;
					}
				}

				if(isQueueEmpty){
					queueEmpty();
				}

				Type res;
				{
					boost::mutex::scoped_lock _(_tsafe);
					res = _quu.front();
					_quu.pop();
				}

				return res;
			}
		private:
			void queueEmpty(){
				_readLock.lock();
			}

			void queueNotEmpty(){
				_readLock.unlock();
			}
			
			void canNotWriteIn(){
				_writeLock.lock();
			}
			void canWriteIn(){
				_writeLock.unlock();
			}
		private:
			const size_t _MAX_SIZE;
			std::queue<Type> _quu;
			boost::mutex _tsafe;//for thread safe.
			std::mutex _readLock;    //read means read from channel;
			std::mutex _writeLock;   //write means write to channel;
	};
}

#endif /* end of include guard: CHANNEL_H_IZJI8D3M */
