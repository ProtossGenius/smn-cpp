

sm_build_subdir_0:
	cd pb && make sm_build_all

sm_clean_subdir_0:
	cd pb && make sm_clean_o

sm_build_subdir_1:
	cd smn_itf && make sm_build_all

sm_clean_subdir_1:
	cd smn_itf && make sm_clean_o
sm_build_all: sm_build_subdir_0 sm_build_subdir_1
sm_clean_o: sm_clean_subdir_0 sm_clean_subdir_1
	rm -rf ./*.o

