#include "Graph.h"
#include "Vertex.h"
#include <algorithm>

void Graph:: MakeEmptyGraph(int n)
{
	numVertices = n+1; //first is a dummy element
	numEdges = 0;
	adjencyLists.resize(n+1);
	for (int i = 1; i <= n; i++)
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

Graph Graph:: BuildTranspose()
{
	Graph transpose;
	transpose.MakeEmptyGraph(numVertices);

	for(int vertex = 1; vertex < numVertices; vertex++)
	{
		list<int> currNeighborList = adjencyLists[vertex].GetNeighbors();
		for (int neighbor : currNeighborList)
		{
			transpose.adjencyLists[neighbor].AddNeighbor(vertex);
		}
	}
	return transpose;
}

Graph Graph::Sharir_Kosaraju()
{
	Graph transpose;
	list<int> endList, reversedEndList;
	//int* arr = new int[n]();
	//vector<int> arr(n);
	this->DFS();
	transpose = this->BuildTranspose();
	reversedEndList = endList;
	reversedEndList.reverse();
	transpose.DFS();

	
}

void