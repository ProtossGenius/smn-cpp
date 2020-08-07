
client.o: client.cpp ./pb/smn_base.pb.h ./rpc_nitf/pb/rip_rpc_itf.pb.h ./rpc_nitf/pb/smn_base.pb.h ./rpc_nitf/smncpp/lockm.h ./rpc_nitf/smncpp/socket_itf.h ./smncpp/socket_itf.h pb/rip_rpc_itf.pb.h pb/smn_dict.pb.h rpc_nitf/rpc_itf.clt.Login.h smncpp/asio_server.h \
smncpp/base_asio_socket.h smncpp/socket_mtd.h
	g++ -Wall -c client.cpp
server.o: server.cpp ./pb/smn_base.pb.h ./rpc_nitf/pb/rip_rpc_itf.pb.h ./rpc_nitf/pb/smn_base.pb.h ./rpc_nitf/smn_itf/pb/rip_rpc_itf.pb.h ./rpc_nitf/smn_itf/pb/smn_base.pb.h ./rpc_nitf/smn_itf/rpc_itf.Login.h ./rpc_nitf/smn_itf/smncpp/socket_itf.h ./rpc_nitf/smncpp/asio_server.h ./rpc_nitf/smncpp/base_asio_socket.h ./rpc_nitf/smncpp/socket_itf.h \
./smn_itf/pb/rip_rpc_itf.pb.h ./smn_itf/pb/smn_base.pb.h ./smn_itf/smncpp/socket_itf.h ./smncpp/socket_itf.h pb/rip_rpc_itf.pb.h pb/smn_dict.pb.h rpc_nitf/rpc_itf.svr.Login.h smn_itf/rpc_itf.Login.h smncpp/asio_server.h smncpp/base_asio_socket.h \
smncpp/socket_mtd.h
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

