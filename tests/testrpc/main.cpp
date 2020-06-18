#include<iostream>
#include <boost/asio.hpp>

#include "smncpp/socket_mtd.h"
#include "smncpp/base_asio_socket.h"
#include "pb/rip_rpc_itf.pb.h"
#include "pb/smn_base.pb.h"
#include "pb/smn_dict.pb.h"
#include "smn_itf/rpc_itf.Login.h"
#include "rpc_nitf/rpc_itf.clt.Login.h"
using namespace std;
using namespace boost::asio;

int main(){
	io_service ioc;
	ip::tcp::socket socket(ioc);
	ip::tcp::endpoint ep(ip::address_v4::from_string("127.0.0.1"), 7000);
	boost::system::error_code ec;
	socket.connect(ep, ec);
	if (ec){
		cout << boost::system::system_error(ec).what() <<endl;
		return -1;
	}
	try{	
	clt_rpc_rpc_itf::Login l(shared_ptr<smnet::Conn>(new smnet::SMConn(socket)));	
	l.Test2("helo", [](shared_ptr<smnet::Conn> c){
			string str;
			int res = smnet::readString(c, str);
			cout << str <<endl;
			return res;
			});
	}catch(std::string str){
		cout << str <<endl;
	}
}
