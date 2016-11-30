CFLAGS = -std=c++11 -Wall -Werror -g

all: main

main: main.o formfeed.o event.o
	g++ -o executable formfeed.o event.o main.o
main.o: main.cpp
	g++ $(CFLAGS) -c main.cpp
formfeed.o: formfeed.cpp
	g++ $(CFLAGS) -c formfeed.cpp
event.o : event.cpp
	g++ $(CFLAGS) -c event.cpp

clean:
	-rm -rf *.o formfeed