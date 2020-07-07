CC=g++
FLAGS=-Wall -c
##Head
ano_rpc_itf.clt.Login.o: ano_rpc_itf.clt.Login.cpp 
	cc -Wall -c ano_rpc_itf.clt.Login.cpp
ano_rpc_itf.clt.MutiTest.o: ano_rpc_itf.clt.MutiTest.cpp 
	cc -Wall -c ano_rpc_itf.clt.MutiTest.cpp
ano_rpc_itf.svr.Login.o: ano_rpc_itf.svr.Login.cpp 
	cc -Wall -c ano_rpc_itf.svr.Login.cpp
ano_rpc_itf.svr.MutiTest.o: ano_rpc_itf.svr.MutiTest.cpp 
	cc -Wall -c ano_rpc_itf.svr.MutiTest.cpp
rpc_itf.clt.Login.o: rpc_itf.clt.Login.cpp 
	cc -Wall -c rpc_itf.clt.Login.cpp
rpc_itf.clt.MutiTest.o: rpc_itf.clt.MutiTest.cpp 
	cc -Wall -c rpc_itf.clt.MutiTest.cpp
rpc_itf.svr.Login.o: rpc_itf.svr.Login.cpp 
	cc -Wall -c rpc_itf.svr.Login.cpp
rpc_itf.svr.MutiTest.o: rpc_itf.svr.MutiTest.cpp 
	cc -Wall -c rpc_itf.svr.MutiTest.cpp
sm_build_all: ano_rpc_itf.clt.Login.o ano_rpc_itf.clt.MutiTest.o ano_rpc_itf.svr.Login.o ano_rpc_itf.svr.MutiTest.o rpc_itf.clt.Login.o rpc_itf.clt.MutiTest.o rpc_itf.svr.Login.o rpc_itf.svr.MutiTest.o
sm_clean_o:
	rm -rf ./*.o
##Tail
test:

clean:
	rm -rf *.o *.h *.cpp
build:
	g++  -Wall -c *.cpp 











