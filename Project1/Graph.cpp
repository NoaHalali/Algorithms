#include "Graph.h"
#include <algorithm>

void Graph:: MakeEmptyGraph(int n)
{
	numVertices = n+1; //first is a dummy element
	numEdges = 0;
	adjencyList.resize(n+1);
	//vector<list<Vertex>> adjencyList(10);
	//adjencyList[0];
	//for (int i = 0; i < numVertices; i++)
	//{
	//	adjencyList[i] 
	//}
}

bool Graph::IsAdjacent(Vertex u, Vertex v)
{
	//adjencyList[u.getVal()];
	// Vertex found = find(adjencyList[u.getVal()].begin(), adjencyList[u.getVal()].end(), v);
	//bool flag = (find(adjencyList[u.getVal()].begin(), adjencyList[u.getVal()].end(), v) == adjencyList[u.getVal()].end());

	
}

list<Vertex> Graph::GetAdjList(Vertex u)
{
	return adjencyList[u.getVal()];
}

void Graph:: AddEdge(Vertex u, Vertex v)
{
	adjencyList[u.getVal()].push_back(v);
}

void Graph:: RemoveEdge(Vertex u, Vertex v)
{
	adjencyList[u.getVal()].remove(v);
}