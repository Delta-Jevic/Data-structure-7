rungraph :  main.o Graph.o
	g++ -std=c++11 -o runGraph main.o Graph.o

main.o : main.cpp
	g++ -std=c++11 -c main.cpp

Graph.o : Graph.h  Graph.cpp
	g++ -std=c++11 -c Graph.cpp 

clean :
	rm runGraph main.o Graph.oss
