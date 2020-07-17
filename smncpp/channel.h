#ifndef CHANNEL_H_IZJI8D3M
#define CHANNEL_H_IZJI8D3M

#include <queue>
#include <boost/thread/mutex.hpp>

namespace smnet{
	template<typename Type>
	class channel {
		public:
			channel(){_readLock.lock();}

		public:
			void push(const Type& val){
				boost::mutex::scoped_lock(_tsafe);
				unlockRL();
				_quu.push(val);
			}

			void emplace(Type&& val){
				boost::mutex::scoped_lock(_tsafe);
				unlockRL();
				_quu.emplace(val);
			}

			bool empty(){
				boost::mutex::scoped_lock(_tsafe);
				return _quu.empty();
			}

			size_t size(){
				boost::mutex::scoped_lock(_tsafe);
				return _quu.size();
			}

			//one_thread_get should only call from one thread. it's not thread-safe. or willcaused dead lock.
			Type one_thread_get(){
				bool shouldLock = false;
				{//check if need Lock;
					boost::mutex::scoped_lock(_tsafe);
					if (_quu.empty()){
						shouldLock = true;
					}
				}

				if(shouldLock){
					lockRL();
				}

				Type&& res;
				{
					boost::mutex::scoped_lock(_tsafe);
					res = std::move(_quu.front());
					_quu.pop();
					//if after push the queque empty, and make sure the readLock only lock once.(if lock once not block.)
					if(_quu.empty()){ 
						unlockRL();
						unlockRL();
						lockRL();
					}
				}

				return res;
			}
		private:
			void lockRL(){
				_readLock.lock();
			}

			void unlockRL(){
				_readLock.unlock();
			}

		private:
			std::queue<Type> _quu;
			boost::mutex _tsafe;//for thread safe.
			boost::mutex _readLock;
	};
}

#endif /* end of include guard: CHANNEL_H_IZJI8D3M */
