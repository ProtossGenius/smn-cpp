LIBS=-lprotobuf
CC=g++
smn_cpps=$(GOPATH)/src/github.com/ProtossGenius/SureMoonNet/cpppb
cmp_goitf: clean
	smnrpc-autocode -cfg ./datas/cfgs/testrpc.json

build_smncpp:
	cd ./smncpp && make build

build_rpcnitf:
	cd ./rpc_nitf && make build 

test_boost:
	cd tests/testboost && make qrun 
test_proto: cmp_goitf  
	cd ./pb && make build
	cd tests/testproto && make qrun

install:

build: build_smncpp build_rpcnitf 
	
clean:
	cd tests && make clean
	cd ./smncpp && make clean
	cd ./pb && make clean
	cd ./rpc_nitf && make clean
	rm -rf ./smn_itf/*.h
test: test_proto test_boost build 

rely_intall:
	#boost
		#go get -u github.com/ProtossGenius/smntools/cmd/smcfg
		#smcfg -get .
		#smcfg -install libs/boost/download # if download is slow
	smcfg -install libs/boost
