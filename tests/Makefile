
sm_build_all: 
	cd boost_callback && make sm_build_all
	cd testboost && make sm_build_all
	cd testproto && make sm_build_all
	cd testrpc && make sm_build_all
sm_clean_o:
	rm -rf ./*.o
	cd boost_callback && make sm_clean_o
	cd testboost && make sm_clean_o
	cd testproto && make sm_clean_o
	cd testrpc && make sm_clean_o
##Tail
clean:
	cd ./testproto && make clean
	cd ./testboost && make clean
	cd ./testrpc && make clean

