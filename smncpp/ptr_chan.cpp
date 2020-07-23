#include "ptr_chan.h"
#include "lockm.h"
namespace smnet{
	typedef  SMLockMgr lockm;
	ptr_chan::ptr_chan(size_t maxSize, create crt, ptr_act del):
	_MAX_SIZE(maxSize), _crt(crt), _del(del), _head(new ptr_node(crt(), del)), _size(0),
	_writeCnt(0){
		ptr_node* cur = _head;
		for(size_t i = 0; i < maxSize; ++i){
			cur->setNext(new ptr_node(crt(), del));
		}
		cur->setNext(_head->getNext()); // if maxSize = 0, head->_next == head->_last == head;
		_read = _head->getNext();
		_write = _head->getNext();
		canNotRead();
		if(maxSize == 0){
			canNotWriteIn();
		}
	}

	ptr_chan::~ptr_chan(){
		ptr_node* cur = _head;
		while(cur->getNext() != _head){
			auto tmp = cur;
			cur = cur->getNext();
			this->deleteNode(tmp);
		}
		delete _head;
	}

	void ptr_chan::deleteNode(ptr_node* node){
		this->_del(node->getPtr());
		delete node;
	}

	void ptr_chan::push_ptr(ptr_act fcpIn){
		bool isFull = false;
		{
			lockm _(_operLock);
			++_writeCnt;
			if(_write->getNext() != _read){
				++_size;
				fcpIn(_write->getPtr());
			}else{
				isFull = true;
			}
		}

		if(isFull){
			canNotWriteIn();
		}
	}

	void ptr_chan::pop_ptr(ptr_act fcpOut){
		{
			lockm _(_operLock);
		}
	}
}
