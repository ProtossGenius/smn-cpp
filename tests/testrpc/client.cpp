#include<iostream>
#include <boost/asio.hpp>

#include "smncpp/socket_mtd.h"
#include "smncpp/base_asio_socket.h"
#include "smncpp/asio_server.h"
#include "pb/rip_rpc_itf.pb.h"
#include "pb/smn_base.pb.h"
#include "pb/smn_dict.pb.h"
#include "rpc_nitf/rpc_itf.clt.Login.h"
using namespace std;
using namespace boost::asio;


int main(){
	io_service ioc;
	ip::tcp::socket sock(ioc);
	ip::tcp::endpoint ep(ip::address::from_string("127.0.0.1"), 1000);
	sock.connect(ep);
	
	clt_rpc_rpc_itf::Login client(make_shared<smnet::SMConn>(std::move(sock)));

	client.Test2("helo", [](std::shared_ptr<smnet::Conn> c){
			std::string str;
			smnet::readString(c, str);

			cout << str <<endl;
			return 0;
			});
	client.Test2("hello", [](std::shared_ptr<smnet::Conn> c){
			std::string str;
			smnet::readString(c, str);
			cout << str <<endl;
			return 0;
			});
	ioc.run();
}
