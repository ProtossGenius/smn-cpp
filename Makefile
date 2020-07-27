LIBS=-lprotobuf
CC=g++
FLAGS=-Wall -c
smn_cpps=$(GOPATH)/src/github.com/ProtossGenius/SureMoonNet/cpppb
##Head

sm_build: 
	+make -C cpp sm_build
	+make -C datas sm_build
	+make -C docs sm_build
	+make -C rpc_nitf sm_build
	+make -C rpcitf sm_build
	+make -C smncpp sm_build
	+make -C tests sm_build

sm_build_all: 
	+make -C cpp sm_build_all
	+make -C datas sm_build_all
	+make -C docs sm_build_all
	+make -C rpc_nitf sm_build_all
	+make -C rpcitf sm_build_all
	+make -C smncpp sm_build_all
	+make -C tests sm_build_all

sm_clean_o:
	rm -rf ./*.o
	+make -C cpp sm_clean_o
	+make -C datas sm_clean_o
	+make -C docs sm_clean_o
	+make -C rpc_nitf sm_clean_o
	+make -C rpcitf sm_clean_o
	+make -C smncpp sm_clean_o
	+make -C tests sm_clean_o

##Tail
cmp_goitf: 
	smnrpc-autocode -cfg ./datas/cfgs/testrpc.json

test_boost: sm_build_all 
	+make -C tests/testboost qrun 
test_proto: sm_build_all
	+make -C tests/testproto qrun

test_channal: sm_build_all
	+make -C tests/testchannal qrun
install:

build: sm_build_all 

clean: sm_clean_o
	cd tests && make clean
	cd ./smncpp && make clean
	cd ./cpp/pb && make clean
	cd ./rpc_nitf && make clean
	rm -rf ./cpp/smn_itf/*.h
	rm -rf ./datas/proto/*.proto
dotest: test_proto test_boost test_channal 

test:  cmp_goitf 
	smake
	make sm_build -j8
	make dotest -j8

rely_intall:
	#boost
		#go get -u github.com/ProtossGenius/smntools/cmd/smcfg
		#smcfg -get .
		#smcfg -install libs/boost/download # if download is slow
	smcfg -install libs/boost

