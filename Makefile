LIBS=-lprotobuf
CC=g++
FLAGS=-Wall -c
smn_cpps=$(GOPATH)/src/github.com/ProtossGenius/SureMoonNet/cpppb
##Head
sm_build_all: 
	cd cpp && make sm_build_all
	cd datas && make sm_build_all
	cd docs && make sm_build_all
	cd rpc_nitf && make sm_build_all
	cd rpcitf && make sm_build_all
	cd smncpp && make sm_build_all
	cd tests && make sm_build_all
sm_clean_o:
	rm -rf ./*.o
	cd cpp && make sm_clean_o
	cd datas && make sm_clean_o
	cd docs && make sm_clean_o
	cd rpc_nitf && make sm_clean_o
	cd rpcitf && make sm_clean_o
	cd smncpp && make sm_clean_o
	cd tests && make sm_clean_o
##Tail
cmp_goitf: clean
	smnrpc-autocode -cfg ./datas/cfgs/testrpc.json

test_boost: sm_build_all 
	cd tests/testboost && make qrun 
test_proto: sm_build_all
	cd ./cpp/pb && make build
	cd tests/testproto && make qrun

install:

build: sm_build_all 

smake:
	smake

clean: sm_clean_o
	cd tests && make clean
	cd ./smncpp && make clean
	cd ./cpp/pb && make clean
	cd ./rpc_nitf && make clean
	rm -rf ./cpp/smn_itf/*.h
test: cmp_goitf smake test_proto test_boost 
	
rely_intall:
	#boost
		#go get -u github.com/ProtossGenius/smntools/cmd/smcfg
		#smcfg -get .
		#smcfg -install libs/boost/download # if download is slow
	smcfg -install libs/boost

