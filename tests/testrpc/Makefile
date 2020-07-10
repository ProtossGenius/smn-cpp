
client.o: client.cpp smncpp/socket_mtd.h smncpp/base_asio_socket.h smncpp/asio_server.h pb/rip_rpc_itf.pb.h pb/smn_base.pb.h pb/smn_dict.pb.h rpc_nitf/rpc_itf.clt.Login.h
	g++ -Wall -c client.cpp
server.o: server.cpp smncpp/socket_mtd.h smncpp/base_asio_socket.h smncpp/asio_server.h pb/rip_rpc_itf.pb.h pb/smn_base.pb.h pb/smn_dict.pb.h smn_itf/rpc_itf.Login.h rpc_nitf/rpc_itf.svr.Login.h
	g++ -Wall -c server.cpp
sm_build_all: client.o server.o
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

