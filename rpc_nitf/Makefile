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
rpc_itf.clt.MutiTest.o: rpc_itf.clt.MutiTest.cpp rpc_itf.clt.MutiTest.h smncpp/socket_itf.h smncpp/socket_mtd.h pb/smn_dict.pb.h pb/smn_base.pb.h pb/rip_rpc_itf.pb.h
	g++ -Wall -c rpc_itf.clt.MutiTest.cpp
rpc_itf.svr.Login.o: rpc_itf.svr.Login.cpp rpc_itf.svr.Login.h smncpp/socket_mtd.h pb/rip_rpc_itf.pb.h pb/smn_base.pb.h pb/smn_dict.pb.h
	g++ -Wall -c rpc_itf.svr.Login.cpp
rpc_itf.svr.MutiTest.o: rpc_itf.svr.MutiTest.cpp rpc_itf.svr.MutiTest.h smncpp/socket_mtd.h pb/rip_rpc_itf.pb.h pb/smn_base.pb.h pb/smn_dict.pb.h
	g++ -Wall -c rpc_itf.svr.MutiTest.cpp

sm_build_subdir_0:
	cd pb && make sm_build_all

sm_clean_subdir_0:
	cd pb && make sm_clean_o

sm_build_subdir_1:
	cd smn_itf && make sm_build_all

sm_clean_subdir_1:
	cd smn_itf && make sm_clean_o

sm_build_subdir_2:
	cd smncpp && make sm_build_all

sm_clean_subdir_2:
	cd smncpp && make sm_clean_o
sm_build_all: ano_rpc_itf.clt.Login.o ano_rpc_itf.clt.MutiTest.o ano_rpc_itf.svr.Login.o ano_rpc_itf.svr.MutiTest.o rpc_itf.clt.Login.o rpc_itf.clt.MutiTest.o rpc_itf.svr.Login.o rpc_itf.svr.MutiTest.o sm_build_subdir_0 sm_build_subdir_1\
sm_build_subdir_2
sm_clean_o: sm_clean_subdir_0 sm_clean_subdir_1 sm_clean_subdir_2
	rm -rf ./*.o
##Tail
test:

clean:
	rm -rf *.o *.h *.cpp
build:
	g++  -Wall -c *.cpp 

