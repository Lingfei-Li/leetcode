all: auto 
#all: man 

CFLAGS += -std=c++11
CFLAGS += -g
CFLAGS += -Wall

compile:
	g++ $(STD) $(CFLAGS) *.cpp

man:
	g++ $(STD) $(CFLAGS) *.cpp
	./a.out

auto:
	g++ $(STD) *.cpp $(CFLAGS) 
	./a.out < in.txt
