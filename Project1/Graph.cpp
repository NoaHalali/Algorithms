#include "Graph.h"
#include "Vertex.h"
#include <algorithm>
#include <string>

enum {WHITE=0, GRAY=1, BLACK=2};

int Graph::getNumVertices()
{
	return numVertices;
}
int Graph::getNumEdges()
{
	return numEdges;
}

void Graph::MakeEmptyGraph(int n)
{
	numVertices = n; 
	numEdges = 0;
	adjencyLists.resize(n + 1); //first is a dummy element
	for (int i = 1; i <= n; i++)
	{
		adjencyLists[i].SetVal(i);
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

void Graph::AddEdge(int u, int v)
{

	adjencyLists[u].AddNeighbor(v);
	numEdges++;
}

void Graph::RemoveEdge(int u, int v)
{
	adjencyLists[u].RemoveNeighbor(v);
}

Graph Graph::BuildTranspose()
{
	Graph transpose;
	transpose.MakeEmptyGraph(numVertices);

	for (int vertex = 1; vertex <= numVertices; vertex++)
	{
		list<int> currNeighborList = adjencyLists[vertex].GetNeighbors();
		for (int neighbor : currNeighborList)
		{
			transpose.adjencyLists[neighbor].AddNeighbor(vertex);
		}
	}
	return transpose;
}

void Graph::Sharir_Kosaraju(Graph& superGraph)
{
	Graph transpose;
	list<int> endList, reversedEndList;

	//DFS on G that returns the end list of the vertices
	this->endListVersionDFS(endList);
	//build G transpose
	transpose = this->BuildTranspose();

	reversedEndList = endList;
	reversedEndList.reverse();
	//DFS on G transpose with maintenance of tree roots
	transpose.treesVersionDFS(reversedEndList, superGraph);
}

void Graph::endListVersionDFS(list<int>& endList)
{
	vector<int> colors(numVertices+1);
	init(colors);

	//main-loop 1,2,3..,n
	for (int i = 1; i <= numVertices; i++)
	{
		if (colors[i] == WHITE)
		{
			visitEndListDFS(i, endList, colors);
		}
	}
}

void Graph::treesVersionDFS(list<int> mainLoop, Graph& superGraph)
{
	int currentComponent = 0;
	vector<int> colors(numVertices+1);
	init(colors);

	vector<int> rootsArr(numVertices+1);

	for (int u : mainLoop)
	{
		if (colors[u] == WHITE)
		{
			currentComponent++;
			superGraph.addVertex(u);
			visitTreesDFS(u, currentComponent, rootsArr, colors, superGraph);
		}
	}
}

void Graph::visitTreesDFS(int u, int currentComponent, vector<int>& rootsArr ,
	vector<int>& colors, Graph& superGraph)
{
	list<int> neighbors = GetAdjList(u);
	rootsArr[u] = currentComponent;
	colors[u] = GRAY;

	for (int vertex : neighbors)
	{
		if (colors[vertex] == WHITE)
		{
			visitTreesDFS(vertex, currentComponent, rootsArr, colors, superGraph);
		}
		else if (rootsArr[vertex] != currentComponent)
		{
			if (!superGraph.isAdjacentInSuperGraph(rootsArr[vertex], currentComponent))
			{
				superGraph.AddEdge(rootsArr[vertex], currentComponent);
			}
		}
	}

	colors[u] = BLACK;
}

void Graph::visitEndListDFS(int u, list<int>& endList, vector<int>& colors)
{
	list<int> neighbors = GetAdjList(u);
	colors[u] = GRAY;

	for (int vertex : neighbors)
	{
		if (colors[vertex] == WHITE)
		{
			visitEndListDFS(vertex, endList, colors);
		}
	}

	colors[u] = BLACK;
	endList.push_back(u);
}

void Graph::init(vector<int>& colors)
{
	for (int color : colors)
	{
		color = WHITE;
	}
}

bool Graph::isAdjacentInSuperGraph(int u, int v)
{
	bool isAdjacent;
	if (adjencyLists[u].isEmptyNeighborsList())
	{
		isAdjacent = false;
	}
	else
	{
		int lastNeighborOfU = adjencyLists[u].getLastNeighborInList();
		isAdjacent = (lastNeighborOfU == v);
	}
	
	return isAdjacent;
}

void Graph::addVertex(int u)
{
	adjencyLists.push_back(Vertex(u));
	numVertices++;
}
