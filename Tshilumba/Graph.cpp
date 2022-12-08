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



Graph::Graph(const string file)         // paramaterized constructor creates to describe graph the graph and describe graph file name passed in default name graph.dat uses filAdjMatrix
{
    fillAdjMatrix(file);                //  uses filAdjMatrix
}


Graph::~Graph()                        // destrutor(does nothing)
{
    
}


void Graph::dijkstra()                // dijkstra perfoms dijkstra's algorithm on the graph
{
    int T = nodesUsedCount;

    do
    {
        int i, j, k;
        GElement first, v, l, minimum = UINT_MAX;

        for (i = 0; i < T; i++)
        {   
            distArray[i] = adjMatrix[1][i]; }

        
        fillVisitedSet();

        first = getFirstNode();

        for (j = 0; j < T; j++)
        {   
            for (k = 0; k < T; k++)
            {  
                if (visitedSet[k] == false && distArray[k] <= minimum)
                {   
                    minimum = distArray[k];
                    v = k; 
                }
            }

            visitedSet[v] = true;

            for (l = 0; l < T; l++)
            {   
                if ( !visitedSet[l] && adjMatrix[v][l] && ( distArray[v] != UINT_MAX )
                     && ( distArray[v] + adjMatrix[v][l] < distArray[l]) )

                {   
                    distArray[l] = distArray[v] + adjMatrix[v][l];  
                }
            }
        }

        distArray[first] = 0;

        view();

    } 
    while (runAgain() == 1);  
}


void Graph::fillAdjMatrix(const string file)  // initializes the graph using the graph data contained within the graph file. Opend use the element of the file
{
    
    int T, v, E, C;

    ifstream inFile;
    inFile.open(file);
    if (!inFile)
    {
        cout << "Error!" << endl;
    }

    else
    {
        
        inFile >> T;

        for (v = 0; v < T; v++)
        {
            for (E = 0; E < T; E++)
            {
                C = 0;

                inFile >> adjMatrix[v][E];
            }

            nodesUsedCount++;
        }

        inFile.close();
    }
}


void Graph::fillVisitedSet()      //Intializes the set of nodes to all univisited - all falseS
{
    int i, T = nodesUsedCount;


    for( i = 0; i < T; i++)
    {
        visitedSet[ i ] = 0;
    }

}


unsigned Graph::getFirstNode() const       //prompts the user for the starting node. validate the entered starting node – prompt until a valid one is entered
{
    GElement first;

    cout << "Enter an integer to start using the graph:  "<<endl;
    
    while (!(cin >> first) || (int)first <= 0 || first > nodesUsedCount) 
    {
        cout << " Enter an unsigned integer:  "<<endl;

        cin.clear();
        cin.ignore(123, '\n');
    } 

    return first;
}


void Graph::view() const                  //displays the contents of the distance array – see required output format below
{
    int i, T = nodesUsedCount;

    for( i = 0; i < T; i++)
    {
        cout << "Distance[" << i << "] = " << distArray[i] << endl;
    }
}

bool Graph::runAgain() const                //prompt the user to see if they wish to run dijkstra again using the same graph allow dijkstra to be run multiple times on the same graph before quitting

{
    bool check;

   
    cout << "Do you want to run again? Enter a '1' for yes or a '0' for no:  ";
    
   
    while (!(cin >> check) || check < 0 || check > 1)
    {
        cout << "  Please enter a '1' or a '0':  ";

        cin.clear();
        cin.ignore(123, '\n');
    } 

    return check;
}
