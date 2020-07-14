
sm_build_all: 
sm_clean_o:
	rm -rf ./*.o
##Tail
clean:
	rm -f *.o main file

build:
	g++ ./hello.cpp -o main -L/usr/local/lib -lboost_serialization

qrun: build
	./main

