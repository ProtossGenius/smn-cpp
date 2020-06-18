#ifndef BASE_ASIO_SOCKET_H_B7IOQTNM
#define BASE_ASIO_SOCKET_H_B7IOQTNM

#include <boost/asio.hpp>
#include "socket_itf.h"
namespace smnet{

enum {BUFF_SIZE = 1024};

class SMConn :public Conn{
typedef boost::asio::ip::tcp::socket socket;
public:
	SMConn(socket& s, size_t buffSize = BUFF_SIZE):_socket(s), 
	BuffSize(buffSize), 
	_buffer(new char[BuffSize]),
	closeFlag(false){}
	~SMConn()override{
		delete[]_buffer;
		if (!closeFlag){
			_socket.close();
		}
	}
	const int read(size_t n, char * bytes) const override;
	const int write(size_t n, const char *bytes) const override;
	const void close() const override;
	const std::string lastError()const override{
		return this->_err.message();
	}

private:
	socket& _socket;	
	const size_t BuffSize;
	char* _buffer;
	mutable bool closeFlag;
	mutable boost::system::error_code _err;
};

}

#endif /* end of include guard: BASE_ASIO_SOCKET_H_B7IOQTNM */
