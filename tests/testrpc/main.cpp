#include<iostream>
#include <boost/asio.hpp>

#include "smncpp/socket_mtd.h"
#include "smncpp/base_asio_socket.h"
#include "smncpp/asio_server.h"
#include "pb/rip_rpc_itf.pb.h"
#include "pb/smn_base.pb.h"
#include "pb/smn_dict.pb.h"
#include "smn_itf/rpc_itf.Login.h"
#include "rpc_nitf/rpc_itf.svr.Login.h"
using namespace std;
using namespace boost::asio;

class Login: public rpc_itf::Login{
public:
	rip_rpc_itf::Login_DoLogin_Ret DoLogin(const std::string& user, const std::string& pswd, int64_t code)override  {
		cout << "Hello " << user << " whose pswd = " << pswd<<endl;
		return rip_rpc_itf::Login_DoLogin_Ret();
	}

	std::vector<int64_t> Test1(const std::vector<std::string>& a, const std::vector<int64_t>& b, const std::vector<uint64_t>& c, const std::vector<uint64_t>& d, const std::vector<int32_t>& e) override {
		throw std::runtime_error("a runtime error");
	} 

	bool Test2(const std::string& key, std::shared_ptr<smnet::Conn>  c) override{
		if (key == "hello"){
			smnet::writeString(c, "hahahahahaha");
		}else{
			smnet::writeString(c, "hehehehe");
		}
		return true;
	}
};


shared_ptr<svr_rpc_rpc_itf::Login> NewLoginServer(ip::tcp::socket sock){
	return make_shared<svr_rpc_rpc_itf::Login>(std::move(sock), make_shared<Login>());
}

int main(){
	io_service ioc;
	smnet::Server s(ioc, 700, NewLoginServer);
	s.start();
	ioc.run();
}
