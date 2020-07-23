#ifndef PTR_CHAN_H_5U372OQT
#define PTR_CHAN_H_5U372OQT
#include <cstddef>
#include <mutex>

namespace smnet{
typedef void(*ptr_act)(void*);
typedef void* (*create) ();

class ptr_node;
class ptr_chan{
	public:
		ptr_chan(size_t maxSize, create crt, ptr_act del);
		~ptr_chan();
		//can't copy.
		ptr_chan(const ptr_chan&) = delete;
		ptr_chan(ptr_chan&&) = delete;
		ptr_chan& operator=(const ptr_chan& ) = delete;
		ptr_chan& operator=(ptr_chan&& ) = delete;
	public:
		void push_ptr(ptr_act fcpIn);
		void pop_ptr(ptr_act fcpOut);
		size_t size(){return _size;}
	private:
		void deleteNode(ptr_node* node);
		void canNotWriteIn();
		void canWriteIn();
		void waitWriteLock();
		void canNotRead();
		void canRead();
		void waitReadLock();
	private:
		const size_t _MAX_SIZE;
		create _crt;	
		ptr_act _del;
		ptr_node* _head;
		ptr_node* _read;
		ptr_node* _write;
		size_t _size;
		size_t _writeCnt;
		std::mutex _operLock;
		std::mutex _readLock;
		std::mutex _writeLock;
};

class ptr_node{
	public:
		ptr_node(void* ptr, ptr_act del);

	public:
		ptr_node* getLast(){return _last;}
		ptr_node* getNext(){return _next;}
			void setLast(ptr_node* last){
			this->_last = last;
			last->_next = this;
		}

		void setNext(ptr_node* next){
			this->_next = next;
			next->_last = this;
		}

		void* getPtr(){return _pointer;}
	private:
		void* _pointer;
		ptr_node* _last;
		ptr_node* _next;
};

}
#endif /* end of include guard: PTR_CHAN_H_5U372OQT */
