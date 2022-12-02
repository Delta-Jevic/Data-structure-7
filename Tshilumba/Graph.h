// General description of the ADT and supported operations – exportable operations only
// Do not include any implementation details
#pragma once
typedef unsigned GElement;

class Graph 
{
    public:                 

        explicit Graph(const std::string = "graph.dat");
        ~Graph();
        void dijkstra();

    private:                

        enum GraphLimit {GRAPH_MAX = 25};
        Graph(const Graph &) = delete;
        void fillAdjMatrix(const std::string );
        void fillVisitedSet();
        unsigned getFirstNode() const;
        void view() const;
        bool runAgain() const;
        
        GElement adjMatrix[GRAPH_MAX][GRAPH_MAX];
        GElement distArray[GRAPH_MAX];
        bool visitedSet[GRAPH_MAX];
        unsigned nodesUsedCount;
};
