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

Graph Graph::Sharir_Kosaraju(Graph& superGraph)
{
	Graph transpose, superGraph;
	list<int> endList, reversedEndList;
	//int* arr = new int[n]();
	//vector<int> arr(n);
	
	//DFS on G that returns end list of vertices
	this->endListVersionDFS(endList);
	//build G transpose
	transpose = this->BuildTranspose();
	
	reversedEndList = endList;
	reversedEndList.reverse();
	//DFS on G transpose that returns the DFS trees
	// אולי להחזיר אותם בתור מערך שבו כל קודקוד יודע לאיזה רכיב קשירות/שורש של עץ הוא שייך בטרנספוז
	// וזה בעצם מחלק אותם לרק"חים  
	transpose.treesVersionDFS(reversedEndList, superGraph);
}

void Graph::endListVersionDFS(list<int>& endList)
{
	vector<string> colors;
	colors.resize(10);

	//init
	for (string color : colors)
	{
		color = "White";
	}

	//main-loop
	for (ver)
}


void Graph::treesVersionDFS(list<int> mainLoop, Graph& superGraph)
{
	/*בכל פעם שהאלגוריתם מתחיל לייצר עץ, העץ מייצג רק"ח כלומר קדקוד בגרף העל.
	  נוסיף קדקוד זה למערך הקדקודים של גרף העל
		superGraph.addVertex(i);
	*/

}
