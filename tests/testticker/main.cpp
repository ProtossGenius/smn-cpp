#include <iostream>

#include "smncpp/ticker.h"
using namespace std;


int main(){
	auto& tm = smnet::GetTickManager();
	auto ticker = tm.getTicker(10);
	for(int i= 0; i < 5; ++i){
		ticker->tick();
		cout << "ticker" <<endl;
	}
	return 0;
}
