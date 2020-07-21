#include <iostream>
#include <boost/thread/thread.hpp>
#include <boost/bind/bind.hpp>
#include <boost/thread/thread.hpp>

#include "smncpp/channel.h"
using namespace std;

smnet::channel<int> chan{500};

void fillNum(int id){
	for (int i = 0; i < 10000; ++i){
		chan.push(id * 10000 + i);
	}
}

void getNum(){
	vector<vector<int> > result(100);
	int val;
	for(int i = 0; i < 1000000; ++i){
		val = chan.one_thread_get();
		int idx = val / 10000, idv = val % 10000;
		result[idx].push_back(idv);
		auto& cur = result[idx];
		auto size =  cur.size();
		if(size == 1 && idv != 0){
			cout << "===== " << val <<endl;
			throw runtime_error("first number not zero.");
		}
		if(size > 1 && cur[size-1] - cur[size-2] != 1){
			cout << "out of order: idx = " << idx <<" , last = " << cur[size-2] << " , cur = "
				<< cur[size-1] <<endl;
			//throw runtime_error("out of order.");
		}
	}
}

int main(){
	boost::thread_group group;
	for(int i = 0; i < 100; ++i){
		group.create_thread(boost::bind(fillNum, i));
	}

	group.create_thread(getNum);

	group.join_all();
	return 0;
}
