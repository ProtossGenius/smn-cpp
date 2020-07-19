

sm_build_subdir_0:
	cd anyTest && make sm_build_all

sm_clean_subdir_0:
	cd anyTest && make sm_clean_o

sm_build_subdir_1:
	cd testboost && make sm_build_all

sm_clean_subdir_1:
	cd testboost && make sm_clean_o

sm_build_subdir_2:
	cd testchannal && make sm_build_all

sm_clean_subdir_2:
	cd testchannal && make sm_clean_o

sm_build_subdir_3:
	cd testproto && make sm_build_all

sm_clean_subdir_3:
	cd testproto && make sm_clean_o

sm_build_subdir_4:
	cd testrpc && make sm_build_all

sm_clean_subdir_4:
	cd testrpc && make sm_clean_o
sm_build_all: sm_build_subdir_0 sm_build_subdir_1 sm_build_subdir_2 sm_build_subdir_3 sm_build_subdir_4
sm_clean_o: sm_clean_subdir_0 sm_clean_subdir_1 sm_clean_subdir_2 sm_clean_subdir_3 sm_clean_subdir_4
	rm -rf ./*.o
##Tail
clean:
	cd ./testproto && make clean
	cd ./testboost && make clean
	cd ./testrpc && make clean
	cd ./anyTest && make clean
	cd ./testchannal && make clean

