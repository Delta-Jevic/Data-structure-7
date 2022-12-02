rungraph :  main.o Graph.o
	g++ -std=c++11 -o rungraph main.o Graph.o

main.o : main.cpp
	g++ -std=c++11 -c main.cpp

Graph.o : Graph.h  Graph.cpp
	g++ -std=c++11 -c Graph.cpp Graph.h

clean :
	rm rungraph main.o Graph.o