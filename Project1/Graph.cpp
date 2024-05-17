#include "Graph.h"
#include "Vertex.h"
#include <algorithm>

void Graph:: MakeEmptyGraph(int n)
{
	numVertices = n+1; //first is a dummy element
	numEdges = 0;
	adjencyLists.resize(n+1);
	for (int i = 0; i < n + 1; i++)
	{
		adjencyLists[i].SetVal(i);
		//adjencyLists[i] = Vertex(i);
	}
}

bool Graph::IsAdjacent(int u, int v)
{
	if (adjencyLists[u].IsNeighbor(v))
	{
		return true;
	}
	return false;
}

list<int> Graph::GetAdjList(int u)
{
	return adjencyLists[u].GetNeighbors();
}

void Graph:: AddEdge(int u, int v)
{

	adjencyLists[u].AddNeighbor(v);
		
	//adjencyLists[u.getVal()].push_back(v);
}

void Graph:: RemoveEdge(int u, int v)
{
	adjencyLists[u].RemoveNeighbor(v);
}