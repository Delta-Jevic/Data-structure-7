/*
Name: Jevic Tshilumba
Class: CSC 300
Professor: Ken Gamradt
Comment: This program creates a user-defined abstract Data type named Graph
The Graph ADT will define and implement the following data types and operations.
*/ 

#include <iostream>             
#include <fstream>
#include <string>
#include <climits>
#include "Graph.h"
using namespace std;            

int main () 
{
    // local variables
    string file = "graph.dat";
    Graph myGraph;
    myGraph.dijkstra();

    return 0;
}
