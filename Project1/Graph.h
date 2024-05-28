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

public:
	void MakeEmptyGraph(int n=0);
	bool IsAdjacent(int u, int v);
	list<int> GetAdjList(int u);
	void AddEdge(int u, int v);
	void RemoveEdge(int u, int v);
	Graph BuildTranspose();
	void Sharir_Kosaraju(Graph& superGraph);
	void endListVersionDFS(list<int>& endList);
	void treesVersionDFS(list<int> mainLoop, Graph& superGraph);
	int getNumVertices();
	int getNumEdges();
	void visitEndListDFS(int u, list<int>& endList, vector<int>& colors);
	void visitTreesDFS(int u, int currentComponent, vector<int>& rootsArr,
		vector<int>& colors, Graph& superGraph);
	void init(vector<int>& colors);
	bool isAdjacentInSuperGraph(int u, int v);
	void addVertex(int u);

};

#endif