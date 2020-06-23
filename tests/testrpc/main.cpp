#include<iostream>
#include <boost/asio.hpp>

#include "smncpp/socket_mtd.h"
#include "smncpp/base_asio_socket.h"
#include "smncpp/asio_server.h"
#include "pb/rip_rpc_itf.pb.h"
#include "pb/smn_base.pb.h"
#include "pb/smn_dict.pb.h"
#include "smn_itf/rpc_itf.Login.h"
#include "rpc_nitf/rpc_itf.clt.Login.h"
using namespace std;
using namespace boost::asio;

class LoginServer:public smnet::Session{
	typedef  boost::asio::ip::tcp tcp;
	public:
		LoginServer(tcp::socket socket, std::shared_ptr<rpc_itf::Login> itf):Session(std::move(socket)), _itf(itf), readLen(0), pReadLen(static_cast<char*>((void*)&readLen)){}
		void run() override{
			auto self = shared_from_this();
			auto& sock = this->_conn->getSocket();
			sock.async_read_some(boost::asio::buffer(pReadLen, 4), [this, self](boost::system::error_code ec, 
						std::size_t readLen){
					if (ec){return;}
					if (readLen < 4){return;}
					smnet::netEdianChange<size_t>(pReadLen);
					smnet::Bytes buff(readLen);
					this->_conn->read(readLen, buff.arr);
					smn_base::Call call;
					call.ParseFromArray(buff.arr, buff.size());
					switch(call.dict()){
					case smn_dict::rip_rpc_itf_Login_Test1_Prm:
					}
					rip_rpc_itf::Login_Test1_Prm prm;
					prm.ParseFromString(call.msg());
					smnet::writePb(this->_conn,Test1(prm));
					run();
				});
		}
	
		rip_rpc_itf::Login_Test1_Ret Test1(const rip_rpc_itf::Login_Test1_Prm& prm);
	public:		
		void pack(const google::protobuf::Message& pb){
			smn_base::Ret ret;
			ret.ParseFromString(pb.SerializeAsString());
			smnet::writePb(this->_conn,ret);
		}
	private:
		std::shared_ptr<rpc_itf::Login> _itf;
		size_t readLen;
		char *pReadLen;

};

shared_ptr<LoginServer> NewLoginServer(ip::tcp::socket sock){
	return make_shared<LoginServer>(std::move(sock));
}

int main(){
	io_service ioc;
	smnet::Server s(ioc, 700, NewLoginServer);
	s.start();
	ioc.run();
}
