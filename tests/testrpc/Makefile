
sm_build_all: 
	cd pb && make sm_build_all
	cd rpc_nitf && make sm_build_all
	cd smn_itf && make sm_build_all
	cd smncpp && make sm_build_all
sm_clean_o:
	rm -rf ./*.o
##Tail
debug:
test:

install:

client: sm_build_all
	g++  ./client.o ./rpc_nitf/*.o ./pb/*.o ./smncpp/*.o  -o run.main -lprotobuf -lpthread `pkg-config --cflags --libs protobuf` 

server: sm_build_all
	g++  ./server.o ./rpc_nitf/*.o ./pb/*.o ./smncpp/*.o  -o run.main -lprotobuf -lpthread `pkg-config --cflags --libs protobuf` 

qrun: client 
	./run.main

clean: 
	rm -f ./run.* ./*.o

