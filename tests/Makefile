
sm_build: 
	+make -C anyTest sm_build
	+make -C testboost sm_build
	+make -C testchannal sm_build
	+make -C testproto sm_build
	+make -C testrpc sm_build
	+make -C testticker sm_build

sm_build_all: 
	+make -C anyTest sm_build_all
	+make -C testboost sm_build_all
	+make -C testchannal sm_build_all
	+make -C testproto sm_build_all
	+make -C testrpc sm_build_all
	+make -C testticker sm_build_all

sm_clean_o:
	rm -rf ./*.o ./run.main
	+make -C anyTest sm_clean_o
	+make -C testboost sm_clean_o
	+make -C testchannal sm_clean_o
	+make -C testproto sm_clean_o
	+make -C testrpc sm_clean_o
	+make -C testticker sm_clean_o

##Tail
clean:
	+make -C testproto clean
	+make -C testboost clean 
	+make -C testrpc clean
	+make -C anyTest clean
	+make -C testchannal clean
	+make -C ./testticker clean

test:
	+make -C testproto qrun
	+make -C testchannal qrun
	+make -C testchannal qrun
	+make -C testticker qrun	

