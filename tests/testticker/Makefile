
main.o: main.cpp ./smncpp/channel.h ./smncpp/lockm.h smncpp/ticker.h
	g++ -Wall -c main.cpp
sm_build: main.o


sm_build_all: main.o
	+make -C smncpp sm_build_all

sm_clean_o:
	rm -rf ./*.o ./run.main


##Tail

qrun: sm_build_all
	g++ -g ./*.o ./smncpp/*.o -lpthread -o run.main 
	time  ./run.main

clean: sm_clean_o
	rm -rf ./*.o  ./run.main

