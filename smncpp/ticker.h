#ifndef TICKER_H_PLB3RWZE
#define TICKER_H_PLB3RWZE
#include <list>
#include <map>
#include "channel.h"
#include <mutex>
#include <memory>
#include <boost/noncopyable.hpp>
namespace smnet{
	class TickUnit;
	class Ticker:boost::noncopyable{
		private:
			Ticker(): _chan(200), _droped(false){
				static int idx = 0;
				this->_idx = idx;
				++idx;
				_chan.setExport(&_tmp);
			}
		public:
			~Ticker(){close();}
		public:
			void tick(); // wait 
			//close remove from It's TickManager
			void close();
		private:
			void put();
		public:
			friend class TickUnit;
		private:
			channel<char> _chan;
			bool _droped;
			char _tmp;
			std::mutex _tsafe;
			int _idx;
	};
	
	//TickUnit this_thiread.sleep(waitTime) and send flag to ticks.
	class TickUnit{
		public:
			TickUnit(int waitTime) :_waitTime(waitTime), _cur(0) {}
		public:
			void tick();
			bool empty(){return _ticks.empty();}
			std::shared_ptr<Ticker> getTicker();
		private:
			int _waitTime; // mill-sec 
			int _cur;
			std::vector<std::shared_ptr<Ticker> > _ticks;
	};

	class TickManager:boost::noncopyable{
		private:
			TickManager();
		public:
			//get a ticker tick per tickMs millsec;if tickMs == 0, return nullptr;
			std::shared_ptr<Ticker> getTicker(int tickMs);
		public:
			static TickManager* Instance();
		private:
			std::shared_ptr<Ticker> _get_ticker(int tickMs);
			void tickLoop();
		private:
			std::mutex _tsafe;
			std::mutex _emptyLock;//organization idling
			std::map<int, std::shared_ptr<TickUnit> > _tunits;
	};
}


#endif /* end of include guard: TICKER_H_PLB3RWZE */
