CC=g++
FLAGS= -Wall -c

##Head

rip_ano_rpc_itf.pb.o: rip_ano_rpc_itf.pb.cc ./smn_base.pb.h rip_ano_rpc_itf.pb.h
	g++ -Wall -c rip_ano_rpc_itf.pb.cc
rip_rpc_itf.pb.o: rip_rpc_itf.pb.cc ./smn_base.pb.h rip_rpc_itf.pb.h
	g++ -Wall -c rip_rpc_itf.pb.cc
smn_base.pb.o: smn_base.pb.cc smn_base.pb.h
	g++ -Wall -c smn_base.pb.cc
smn_dict.pb.o: smn_dict.pb.cc smn_dict.pb.h
	g++ -Wall -c smn_dict.pb.cc
sm_build: rip_ano_rpc_itf.pb.o rip_rpc_itf.pb.o smn_base.pb.o smn_dict.pb.o


sm_build_all: rip_ano_rpc_itf.pb.o rip_rpc_itf.pb.o smn_base.pb.o smn_dict.pb.o


sm_clean_o:
	rm -rf ./*.o ./run.main


##Tail
build: sm_build_all 

clean:
	rm -f *.cc *.h *.o

