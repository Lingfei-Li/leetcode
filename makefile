all: auto 
#all: man 

compile:
	g++ -std=c++0x *.cpp -g

man:
	g++ -std=c++0x *.cpp -g
	time a.out

auto:
	g++ -std=c++0x *.cpp -g
	time a.out < in.txt
