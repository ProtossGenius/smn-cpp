#ifndef SOCKET_ITF_H_BY5UU1X9
#define SOCKET_ITF_H_BY5UU1X9

#include <string>
namespace smnet{

enum{ConnStatusSucc = 0};

class Conn{
public:
	virtual ~Conn() {} 
	//read @return error_code.
	virtual const int read(size_t n, char * bytes) const = 0;
	virtual const int write(size_t n, const char *bytes) const = 0;
	virtual const void close() const = 0;
	virtual const std::exception lastError()const =0;
};


}//namespace smnet


#endif /* end of include guard: SOCKET_ITF_H_BY5UU1X9 */
