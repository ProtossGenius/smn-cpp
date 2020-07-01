#include <mutex>

namespace smnet{
	class SMLockMgr{
		public:
		SMLockMgr(std::mutex& lock):_lock(lock){
			lock.lock();
		}
		SMLockMgr(const SMLockMgr& _) = delete ;
		~SMLockMgr(){this->_lock.unlock();}
		private:
		std::mutex& _lock;
	};

}
