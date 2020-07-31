#ifndef LOCKM_H_6O85XWT4
#define LOCKM_H_6O85XWT4


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

#endif /* end of include guard: LOCKM_H_6O85XWT4 */
