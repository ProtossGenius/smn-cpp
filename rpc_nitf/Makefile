CC=g++
FLAGS=-Wall -c
##Head
ano_rpc_itf.clt.Login.o: ano_rpc_itf.clt.Login.cpp ano_rpc_itf.clt.Login.h smncpp/socket_itf.h smncpp/socket_mtd.h pb/smn_base.pb.h pb/rip_ano_rpc_itf.pb.h pb/smn_dict.pb.h
	g++ -Wall -c ano_rpc_itf.clt.Login.cpp
ano_rpc_itf.clt.MutiTest.o: ano_rpc_itf.clt.MutiTest.cpp ano_rpc_itf.clt.MutiTest.h smncpp/socket_itf.h smncpp/socket_mtd.h pb/rip_ano_rpc_itf.pb.h pb/smn_dict.pb.h pb/smn_base.pb.h
	g++ -Wall -c ano_rpc_itf.clt.MutiTest.cpp
ano_rpc_itf.svr.Login.o: ano_rpc_itf.svr.Login.cpp ano_rpc_itf.svr.Login.h smncpp/socket_mtd.h pb/smn_base.pb.h pb/smn_dict.pb.h pb/rip_ano_rpc_itf.pb.h
	g++ -Wall -c ano_rpc_itf.svr.Login.cpp
ano_rpc_itf.svr.MutiTest.o: ano_rpc_itf.svr.MutiTest.cpp ano_rpc_itf.svr.MutiTest.h smncpp/socket_mtd.h pb/smn_base.pb.h pb/smn_dict.pb.h pb/rip_ano_rpc_itf.pb.h
	g++ -Wall -c ano_rpc_itf.svr.MutiTest.cpp
rpc_itf.clt.Login.o: rpc_itf.clt.Login.cpp rpc_itf.clt.Login.h smncpp/socket_itf.h smncpp/socket_mtd.h pb/smn_base.pb.h pb/rip_rpc_itf.pb.h pb/smn_dict.pb.h
	g++ -Wall -c rpc_itf.clt.Login.cpp
rpc_itf.clt.MutiTest.o: rpc_itf.clt.MutiTest.cpp rpc_itf.clt.MutiTest.h smncpp/socket_itf.h smncpp/socket_mtd.h pb/smn_base.pb.h pb/rip_rpc_itf.pb.h pb/smn_dict.pb.h
	g++ -Wall -c rpc_itf.clt.MutiTest.cpp
rpc_itf.svr.Login.o: rpc_itf.svr.Login.cpp rpc_itf.svr.Login.h smncpp/socket_mtd.h pb/smn_base.pb.h pb/smn_dict.pb.h pb/rip_rpc_itf.pb.h
	g++ -Wall -c rpc_itf.svr.Login.cpp
rpc_itf.svr.MutiTest.o: rpc_itf.svr.MutiTest.cpp rpc_itf.svr.MutiTest.h smncpp/socket_mtd.h pb/rip_rpc_itf.pb.h pb/smn_base.pb.h pb/smn_dict.pb.h
	g++ -Wall -c rpc_itf.svr.MutiTest.cpp
sm_build: ano_rpc_itf.clt.Login.o ano_rpc_itf.clt.MutiTest.o ano_rpc_itf.svr.Login.o ano_rpc_itf.svr.MutiTest.o rpc_itf.clt.Login.o rpc_itf.clt.MutiTest.o rpc_itf.svr.Login.o rpc_itf.svr.MutiTest.o


sm_build_all: ano_rpc_itf.clt.Login.o ano_rpc_itf.clt.MutiTest.o ano_rpc_itf.svr.Login.o ano_rpc_itf.svr.MutiTest.o rpc_itf.clt.Login.o rpc_itf.clt.MutiTest.o rpc_itf.svr.Login.o rpc_itf.svr.MutiTest.o
	+make -C pb sm_build_all
	+make -C smn_itf sm_build_all
	+make -C smncpp sm_build_all

sm_clean_o:
	rm -rf ./*.o

##Tail
test:

clean:
	rm -rf *.o *.h *.cpp
build:
	g++  -Wall -c *.cpp 

