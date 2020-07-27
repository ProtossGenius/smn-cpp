
testproto.o: testproto.cpp .//pb/smn_base.pb.h pb/rip_rpc_itf.pb.h
	g++ -Wall -c testproto.cpp
sm_build: testproto.o


sm_build_all: testproto.o
	+make -C pb sm_build_all

sm_clean_o:
	rm -rf ./*.o

##Tail
build:
	g++ pb/*.o *.o  -o testproto -lprotobuf `pkg-config --cflags --libs protobuf` 

qrun: build
	./testproto 

clean: 
	rm -f ./testproto ./*.o

