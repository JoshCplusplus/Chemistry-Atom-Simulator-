a.out: main.cc
	g++ -std=c++11 -Wall -g main.cc atom.h
clean:
	rm a.out
