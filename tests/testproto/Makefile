
testproto.o: testproto.cpp pb/rip_rpc_itf.pb.h
	g++ -Wall -c testproto.cpp
sm_build_all: testproto.o
sm_clean_o:
	rm -rf ./*.o
##Tail
build:
	g++ pb/*.o *.o  -o testproto -lprotobuf `pkg-config --cflags --libs protobuf` 

qrun: build
	./testproto 

clean: 
	rm -f ./testproto ./*.o




















