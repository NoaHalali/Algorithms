#include <iostream>
#include <stdlib.h>
#include "Graph.h"
using namespace std; 


void main()
{

}

void ValidInput()
{
	int numVertices;
	int numEdges;
	Graph graph, transpose;

	//cout << "Enter number of vertices: ";
	cin >> numVertices;
	//cout << "Enter number of edges: ";
	cin >> numEdges;

	if (numVertices == 0 && numEdges > 0)
	{
		cout << "invalid input";
	}
	if (numVertices < 0 || numEdges < 0)
	{
		cout << "invalid input";
	}

	graph.MakeEmptyGraph(numVertices);
	//cout << "Enter " << numEdges << " edges:" << endl;
	for (int i = 1; i <= numEdges; i++)
	{
		int u, v;
		//cout << "Enter edge " << i << endl;
		//cout << "From: ";
		cin >> u;
		//cout << "To: ";
		cin >> v;

		if (IsLoop(v,u))
		{
			cout << "invalid input";
		}

		graph.AddEdge(u, v); //create vertexes
	}
	transpose = graph.BuildTranspose();
	cout << "test 21.5 16:39";

}

bool IsLoop(int u, int v)
{
	if (u == v) return true;
	return false;
}