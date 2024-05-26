#include <iostream>
#include <stdlib.h>
#include "Graph.h"
using namespace std; 

/*This is a program that getting a directed graph data, and build its supergraph in a linear complexity.
* At start, should enter: 
1. integer number of vertices - n
2. integer number of edges -m
3. Couples of integers, each couple in a different line,
   while each couple represents name of 2 vertices (each vertex is an integer between 1 and n)
   the couple i,j will represents the edge (i,j)
*/
void main()
{
	int numVertices;
	int numEdges;
	Graph graph, superGraph /*,transpose*/;
	//להוריד את ההדפסות אח"כ
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
	//transpose = graph.BuildTranspose();

	graph.Sharir_Kosaraju(superGraph);
	cout << superGraph.getNumVertices() << " " << superGraph.getNumEdges();
}