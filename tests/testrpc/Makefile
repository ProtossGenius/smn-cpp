
client.o: client.cpp pb/rip_rpc_itf.pb.h pb/smn_base.pb.h pb/smn_dict.pb.h rpc_nitf/rpc_itf.clt.Login.h smncpp/asio_server.h smncpp/base_asio_socket.h smncpp/socket_mtd.h
	g++ -Wall -c client.cpp
server.o: server.cpp pb/rip_rpc_itf.pb.h pb/smn_base.pb.h pb/smn_dict.pb.h rpc_nitf/rpc_itf.svr.Login.h smn_itf/rpc_itf.Login.h smncpp/asio_server.h smncpp/base_asio_socket.h smncpp/socket_mtd.h
	g++ -Wall -c server.cpp
sm_build: client.o server.o


sm_build_all: client.o server.o
	+make -C pb sm_build_all
	+make -C rpc_nitf sm_build_all
	+make -C smn_itf sm_build_all
	+make -C smncpp sm_build_all

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

