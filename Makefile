all: auto 
#all: man 

CFLAGS += -std=c++11
CFLAGS += -g

compile:
	g++ $(STD) $(CFLAGS) *.cpp

man:
	g++ $(STD) $(CFLAGS) *.cpp
	time ./a.out

auto:
	g++ $(STD) *.cpp $(CFLAGS) 
	time ./a.out < in.txt
