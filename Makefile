a.out: main.cc
	g++ -std=c++11 main.cc atom.h
clean:
	rm a.out
