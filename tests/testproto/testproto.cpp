#include<iostream>
#include "pb/rip_rpc_itf.pb.h"
using namespace std;

int main(){
	rip_rpc_itf::Login_DoLogin_Prm prm;
	prm.set_user("hello");
	cout <<"SAS["<< prm.SerializeAsString() <<"]"<<endl;
	cout << "SPAS["<<prm.SerializePartialAsString() <<"]" <<endl;
	cout << prm.user() << endl;
	cout <<"hello world" <<endl;
	rip_rpc_itf::Login_DoLogin_Prm prm2(prm);
	cout << prm2.user() <<endl;
}
