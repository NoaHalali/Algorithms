#include <iostream>
#include <stdlib.h>
#include "Graph.h"
using namespace std; 


void main()
{
	int numVertices;
	int numEdges;
	Graph graph, transpose;

	cout << "Enter number of vertices: ";
	cin >> numVertices;
	cout << "Enter number of edges: ";
	cin >> numEdges;

	graph.MakeEmptyGraph(numVertices);
	cout << "Enter " << numEdges << " edges:" << endl;
	for (int i = 1; i <= numEdges; i++)
	{
		int u, v;
		cout << "Enter edge " << i <<endl;
		cout << "From: ";
		cin >> u;
		cout << "To: ";
		cin >> v;

		graph.AddEdge(u, v); //create vertexes
	}
	transpose = graph.BuildTranspose();
	cout << "test 21.5 16:00";
}