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
	vector<Vertex> adjencyLists;
	//vector< list<Vertex> > adjencyList;

public:
	void MakeEmptyGraph(int n);
	bool IsAdjacent(int u, int v);
	list<int> GetAdjList(int u);
	void AddEdge(int u, int v);
	void RemoveEdge(int u, int v);
	Graph BuildTranspose();
	//void graphPrint();
	void Sharir_Kosaraju(Graph& superGraph);
	void endListVersionDFS(list<int>& endList);
	void treesVersionDFS(list<int> mainLoop, Graph& superGraph);
	int getNumVertices();
	int getNumEdges();
	void visit(int u, list<int>& endList, vector<string>& colors);
	void init(vector<string>& colors);

};

#endif