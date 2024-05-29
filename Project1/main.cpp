#include <iostream>
#include <stdlib.h>
#include "Graph.h"
//#include "Exception.h"
using namespace std; 

void validateInput(int numVertices, int numEdges);
void validateEdge(int u, int v, int numVertices);

/*This is a program that getting a directed graph data, and build its supergraph in a linear complexity.
* At start, should enter: 
1. integer number of vertices - n
2. integer number of edges -m
3. Couples of integers, each couple in a different line,
   while each couple represents name of 2 vertices (each vertex is an integer between 1 and n)
   the couple i,j will represents the edge (i,j)
*/

class Exception {};

class InvalidVertexException : public Exception {};

class InvalidEdgeException : public Exception {};

class InvalidGraphSizeException : public Exception {};



void validateInput(int numVertices, int numEdges) 
{
	if (numVertices == 0 && numEdges != 0) 
	{
		throw InvalidGraphSizeException();
	}
	if (numVertices < 0 || numEdges < 0) 
	{
		throw InvalidGraphSizeException();
	}

	int maxEdges = numVertices * (numVertices - 1); // nC2 * 2 = (n(n-1)/2 )*2 = n(n-1)
	if (numEdges > maxEdges)
	{
		throw InvalidGraphSizeException();
	}
}


void validateEdge(int u, int v, int numVertices) {
	if (u < 1 || v < 1)
	{
		throw InvalidEdgeException();
	}
	if (u > numVertices || v > numVertices) 
	{
		throw InvalidEdgeException();
	}
	if (u == v)
	{
		throw InvalidEdgeException();
	}

}


int main()
{
	int numVertices;
	int numEdges;
	try
	{
		cin >> numVertices;
		cin >> numEdges;
		validateInput(numVertices, numEdges);
	}
	catch (const Exception& e)
	{
		cout << "invalid input" << endl;
		return 0;
	}

	Graph graph, superGraph;
	graph.MakeEmptyGraph(numVertices);
	for (int i = 0; i < numEdges; ++i) 
	{
		int u, v;

		try
		{
			std::cin >> u;
			std::cin >> v;
			validateEdge(u, v, numVertices);
			graph.AddEdge(u, v);
		}
		catch (const Exception& e)
		{
			cout << "invalid input" << endl;
			return 0;
		}
	}
	superGraph.MakeEmptyGraph();
	graph.Sharir_Kosaraju(superGraph);
	cout << superGraph.getNumVertices() << " " << superGraph.getNumEdges();

	return 0;
}