/*
Name: Jevic Tshilumba
Class: CSC 300
Professor: Ken Gamradt
Comment: This program creates a user-defined abstract Data type named Graph
The Graph ADT will define and implement the following data types and operations.
*/ 

#pragma once
typedef unsigned GElement;

class Graph 
{
    public:                                               // exportable
                                                          // General description of each of the ADT operations/functions – exportable operations only
        explicit Graph(const std::string = "graph.dat");
        ~Graph();
        void dijkstra();

    private:                                             // non-exportable
                                                         // No private member documentation – implementation details are hidden/abstracted away
        enum GraphLimit {GRAPH_MAX = 25};
        Graph(const Graph &) = delete;
        void fillAdjMatrix(const std::string);
        void fillVisitedSet();
        unsigned getFirstNode() const;
        void view() const;
        bool runAgain() const;
        
        GElement adjMatrix[GRAPH_MAX][GRAPH_MAX];
        GElement distArray[GRAPH_MAX];
        bool visitedSet[GRAPH_MAX];
        unsigned nodesUsedCount;
};
