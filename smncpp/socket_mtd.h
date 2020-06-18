#ifndef SOCKET_MTD_H_J7GWOTFX
#define SOCKET_MTD_H_J7GWOTFX
#include <memory>
#include <string>

namespace smnet{

class Bytes {
public:
	Bytes():arr(nullptr), _cnt(nullptr), _len(0){}
	Bytes(size_t len):arr(new char[len]), _cnt(new int(1)), _len(len){}
	Bytes(const Bytes& bytes):arr(bytes.arr), _cnt(bytes._cnt), _len(bytes._len){++(*this->_cnt);}
	Bytes(Bytes&& bytes):arr(bytes.arr), _cnt(bytes._cnt), _len(bytes._len){bytes.arr = nullptr; bytes._cnt = nullptr;}
	~Bytes(){
		drop();	
	}
	void drop(){
		if (this->_cnt == nullptr){return;}
		--(*this->_cnt);
		if ((*this->_cnt) == 0){
			delete this->_cnt;
			delete[] this->arr;
		}
	}
	Bytes& operator= (const Bytes& bytes){
		if (this == &bytes){return *this;}
		drop();
		this->arr = bytes.arr;
		this->_cnt = bytes._cnt;
		this->_len = bytes._len;
		++(*this->_cnt);
		return *this;
	}

	Bytes& operator= (Bytes&& bytes){
		if (this == &bytes){return *this;}
		drop();
		this->arr = bytes.arr;
		this->_cnt = bytes._cnt;
		this->_len = bytes._len;
		bytes.arr = nullptr;
		bytes._cnt = nullptr;
		return *this;
	}

	size_t size(){return _len;}
public:
	char* arr;
private:
	int* _cnt;
	size_t _len;
};

class Conn;

template<typename Struct>
int readStruct(std::shared_ptr<Conn> c, Struct& obj);


template<typename Struct>
int writeStruct(std::shared_ptr<Conn> c, Struct len);


//writeLenBytes  will send byte length before send bytes.
int writeLenBytes(const Conn & c, int32_t len, const char *bytes);

int readLenBytes(std::shared_ptr<Conn> c, Bytes& bytes);

int writeString(std::shared_ptr<Conn> c, std::string& str);

int writeString(std::shared_ptr<Conn> c, std::string&& str);

int readString(std::shared_ptr<Conn> c, std::string& str);

template<class Pb>
int readPb(std::shared_ptr<Conn> c, Pb& pb);

template<class Pb>
int writePb(std::shared_ptr<Conn> c, Pb& pb);

}
#endif /* end of include guard: SOCKET_MTD_H_J7GWOTFX */
