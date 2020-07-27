

sm_build: 
	+make -C anyTest sm_build
	+make -C testboost sm_build
	+make -C testchannal sm_build
	+make -C testproto sm_build
	+make -C testrpc sm_build

sm_build_all: 
	+make -C anyTest sm_build_all
	+make -C testboost sm_build_all
	+make -C testchannal sm_build_all
	+make -C testproto sm_build_all
	+make -C testrpc sm_build_all

sm_clean_o:
	rm -rf ./*.o
	+make -C anyTest sm_clean_o
	+make -C testboost sm_clean_o
	+make -C testchannal sm_clean_o
	+make -C testproto sm_clean_o
	+make -C testrpc sm_clean_o

##Tail
clean:
	cd ./testproto && make clean
	cd ./testboost && make clean
	cd ./testrpc && make clean
	cd ./anyTest && make clean
	cd ./testchannal && make clean

