#include <iostream>
#include <boost/asio.hpp>

using namespace std;

using io_context = boost::asio::io_context;

int main(){
	io_context ioc;
	

	ioc.run();
	return 0;
}
