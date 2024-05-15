#ifndef __GRAPH_H
#define __GRAPH_H

#include "Vertex.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

#include <vector> 
#include <list> 


class Graph
{
	int numVertices;
	int numEdges;
	vector< list<Vertex> > adjencyList;

public:
	void MakeEmptyGraph(int n);
	bool IsAdjacent(Vertex u, Vertex v);
	list<Vertex> GetAdjList(Vertex u);
	void AddEdge(Vertex u, Vertex v);
	void RemoveEdge(Vertex u, Vertex v);
};


#endif