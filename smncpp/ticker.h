#ifndef TICKER_H_PLB3RWZE
#define TICKER_H_PLB3RWZE
#include <list>
#include "channel.h"
#include <mutex>
#include <memory>
#include <boost/noncopyable.hpp>
namespace smnet{
	class TickUnit;
	class Ticker{
		private:
			Ticker(int idx, TickUnit& tu): _chan(200), _idx(idx), _tu(tu){_chan.setExport(&_tmp);}
		public:
			~Ticker(){close();}
		public:
			//close remove from It's TickManager
			void close();
		private:
			void put();
		public:
			friend class TickUnit;
		private:
			channel<char> _chan;
			size_t _idx; // if _idx < 0 means it closed.
			TickUnit& _tu;
			char _tmp;
	};

	//TickUnit this_thiread.sleep(waitTime) and send flag to ticks.
	class TickUnit{
		public:
			TickUnit() {}
		public:
			void remove(int idx);
			void tick();
			int waitTime(){return _waitTime;}
			size_t jump;
		private:
			int _waitTime;
			std::vector<Ticker> _ticks;
	};

	class TickManager:boost::noncopyable{
		private:
			TickManager(){}
		public:
			Ticker getTicker(int tickMs);
		public:
			static TickManager* Install(){
				static TickManager* ins = new TickManager();
				return ins;
			}
		private:
			std::mutex _tsafe;
			std::mutex _emptyLock;//organization idling
			int _total;
			std::list<TickUnit> _list;
	};
}


#endif /* end of include guard: TICKER_H_PLB3RWZE */
