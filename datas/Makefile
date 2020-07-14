

sm_build_subdir_0:
	cd cfgs && make sm_build_all

sm_clean_subdir_0:
	cd cfgs && make sm_clean_o

sm_build_subdir_1:
	cd proto && make sm_build_all

sm_clean_subdir_1:
	cd proto && make sm_clean_o
sm_build_all: sm_build_subdir_0 sm_build_subdir_1
sm_clean_o: sm_clean_subdir_0 sm_clean_subdir_1
	rm -rf ./*.o

