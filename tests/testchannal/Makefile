
main.o: main.cpp smncpp/channel.h
	g++ -Wall -c main.cpp

sm_build_subdir_0:
	cd smncpp && make sm_build_all

sm_clean_subdir_0:
	cd smncpp && make sm_clean_o
sm_build_all: main.o sm_build_subdir_0
sm_clean_o: sm_clean_subdir_0
	rm -rf ./*.o
##Tail

qrun: sm_build_all
	g++ -g ./*.o -lpthread -o run.main -lboost_thread
	time  ./run.main

clean: sm_clean_o
	rm -rf ./*.o  ./run.main

