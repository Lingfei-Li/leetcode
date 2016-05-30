#all: auto 
all: man 

compile:
	g++ -std=c++11 *.cpp -g

man:
	g++ -std=c++11 *.cpp -g
	time ./a.out

auto:
	g++ -std=c++11 *.cpp -g
	time ./a.out < in.txt
