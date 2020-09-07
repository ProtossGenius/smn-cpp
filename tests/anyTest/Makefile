
main.o: main.cpp 
	g++ -Wall -c main.cpp
sm_build: main.o


sm_build_all: main.o


sm_clean_o:
	rm -rf ./*.o ./run.main


##Tail

qrun: sm_build_all
	g++ ./*.o -o run.main
	./run.main

clean:
	rm -rf ./run.main ./*.o

