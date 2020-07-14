CC=g++
FLAGS=-Wall -c
##Head
sm_build_all: 
	cd pb && make sm_build_all
	cd smn_itf && make sm_build_all
	cd smncpp && make sm_build_all
sm_clean_o:
	rm -rf ./*.o
##Tail
test:

clean:
	rm -rf *.o *.h *.cpp
build:
	g++  -Wall -c *.cpp 

