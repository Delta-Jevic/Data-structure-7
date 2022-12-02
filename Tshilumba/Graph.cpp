//NAME	: Jevic Tshilumba
//CLASS	: CSC 300
//ASSIGNMENT	: 7

#include <iostream>             
#include <fstream>
#include <string>
#include <climits>
#include <algorithm>
#include "Graph.h"              
using namespace std;

Graph::Graph(const std::string inFile)
{
    fillAdjMatrix(inFile);
}


void Graph::fillAdjMatrix(const string file)
{
    ifstream inFile;
    inFile.open(file);
    if (!inFile)
    {
        // error message if not opened
        cout << "File not found!" << endl;
        exit(102);
    }
    inFile >> nodesUsedCount;

    for (int i = 0; i < nodesUsedCount; i++)
        for (int j = 0; j < nodesUsedCount; j++)
        {
            inFile >> adjMatrix[i][j];
            distArray[i] = 0;
        }

        // close graph file
        inFile.close();


}



void Graph::view() const
{
    for (int i = 0; i < nodesUsedCount; i++)
    {
        cout << "Distance[" << i << "] = " << distArray[i] << endl;
    }
}

bool Graph::runAgain() const
{
    int check;
    cout << "WOuld you like to run again?" << endl;
    cout << "Enter 1 for yes and 0 for no-";
    cin >> check;
    cout << endl;

    while (check < 0 || check> 1)
    {
        cout << "Please enter 1 if yes or o if no" << endl;
        cin >> check;
    }
    if (check == 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}
