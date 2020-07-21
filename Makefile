LIBS=-lprotobuf
CC=g++
FLAGS=-Wall -c
smn_cpps=$(GOPATH)/src/github.com/ProtossGenius/SureMoonNet/cpppb
##Head

sm_build_subdir_0:
	cd cpp && make sm_build_all

sm_clean_subdir_0:
	cd cpp && make sm_clean_o

sm_build_subdir_1:
	cd datas && make sm_build_all

sm_clean_subdir_1:
	cd datas && make sm_clean_o

sm_build_subdir_2:
	cd docs && make sm_build_all

sm_clean_subdir_2:
	cd docs && make sm_clean_o

sm_build_subdir_3:
	cd rpc_nitf && make sm_build_all

sm_clean_subdir_3:
	cd rpc_nitf && make sm_clean_o

sm_build_subdir_4:
	cd rpcitf && make sm_build_all

sm_clean_subdir_4:
	cd rpcitf && make sm_clean_o

sm_build_subdir_5:
	cd smncpp && make sm_build_all

sm_clean_subdir_5:
	cd smncpp && make sm_clean_o

sm_build_subdir_6:
	cd tests && make sm_build_all

sm_clean_subdir_6:
	cd tests && make sm_clean_o
sm_build_all: sm_build_subdir_0 sm_build_subdir_1 sm_build_subdir_2 sm_build_subdir_3 sm_build_subdir_4 sm_build_subdir_5 sm_build_subdir_6
sm_clean_o: sm_clean_subdir_0 sm_clean_subdir_1 sm_clean_subdir_2 sm_clean_subdir_3 sm_clean_subdir_4 sm_clean_subdir_5 sm_clean_subdir_6
	rm -rf ./*.o
##Tail
cmp_goitf: clean
	smnrpc-autocode -cfg ./datas/cfgs/testrpc.json

test_boost: sm_build_all 
	cd tests/testboost && make qrun 
test_proto: cmp_goitf smake sm_build_all
	cd ./cpp/pb && make build
	cd tests/testproto && make qrun

test_channal: sm_build_all
	cd ./tests/testchannal && make qrun
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
test:  test_proto test_boost test_channal
	
rely_intall:
	#boost
		#go get -u github.com/ProtossGenius/smntools/cmd/smcfg
		#smcfg -get .
		#smcfg -install libs/boost/download # if download is slow
	smcfg -install libs/boost

