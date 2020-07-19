#include <iostream>
#include <boost/thread/thread.hpp>
#include <boost/bind/bind.hpp>
#include <boost/thread/thread.hpp>

#include "smncpp/channel.h"
using namespace std;

smnet::channel<int> chan;

void fillNum(int id){
	for (int i = 0; i < 10; ++i){
		chan.push(id * 10000 + i);
	}
}

void getNum(){
	for(int i = 0; i < 1000; ++i){
		int val = chan.one_thread_get();
		cout << val <<endl;
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
