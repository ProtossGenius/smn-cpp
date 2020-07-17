#ifndef SOCKET_MTD_H_J7GWOTFX
#define SOCKET_MTD_H_J7GWOTFX
#include <memory>
#include <string>
#include <atomic>
namespace smnet{

class Bytes {
public:
	Bytes():arr(nullptr), _cnt(nullptr), _len(0){}
	Bytes(size_t len):arr(new char[len]), _cnt(new std::atomic_int(1)), _len(len){}
	Bytes(const Bytes& bytes):arr(bytes.arr), _cnt(bytes._cnt), _len(bytes._len){++(*this->_cnt);}
	Bytes(Bytes&& bytes):arr(bytes.arr), _cnt(bytes._cnt), _len(bytes._len){bytes.arr = nullptr; bytes._cnt = nullptr;}
	~Bytes();
	Bytes& operator= (const Bytes& bytes){
		Bytes tmp(bytes);
		this->swap(tmp);//get bytes's copy and swap and drop old data..
		return *this;
	}

	Bytes& operator= (Bytes&& bytes){
		if (this == &bytes){return *this;}
		Bytes zero;
		this->swap(bytes);//get bytes's value.
		bytes.swap(zero);//drop this->old data; make right-value save.
		return *this;
	}

	void swap(Bytes& rhs){
		std::swap(rhs.arr, this->arr);
		std::swap(rhs._cnt, this->_cnt);
		std::swap(rhs._len, this->_len);
	}
	size_t size(){return _len;}
public:
	char* arr;
private:
	std::atomic_int* _cnt;
	size_t _len;
};

class Conn;

bool IS_BIG_EDIAN();

void netEdianChange(char *pLen, size_t len);

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

}
#endif /* end of include guard: SOCKET_MTD_H_J7GWOTFX */
