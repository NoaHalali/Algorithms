#include "Graph.h"
#include "Vertex.h"
#include <algorithm>
#include <string>

//#define WHITE 0
//#define GRAY 1
//#define BLACK 2
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

void Graph::AddEdge(int u, int v)
{

	adjencyLists[u].AddNeighbor(v);
	numEdges++;
	//adjencyLists[u.getVal()].push_back(v);
}

void Graph::RemoveEdge(int u, int v)
{
	adjencyLists[u].RemoveNeighbor(v);
}

Graph Graph::BuildTranspose()
{
	Graph transpose;
	transpose.MakeEmptyGraph(numVertices);

	for (int vertex = 1; vertex < numVertices; vertex++)
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
	//int* arr = new int[n]();
	//vector<int> arr(n);

	//DFS on G that returns the end list of the vertices
	this->endListVersionDFS(endList);
	//build G transpose
	transpose = this->BuildTranspose();

	reversedEndList = endList;
	reversedEndList.reverse();
	//DFS on G transpose with maintenance of tree roots
	// אולי להחזיר אותם בתור מערך שבו כל קודקוד יודע לאיזה רכיב קשירות/שורש של עץ הוא שייך בטרנספוז
	// וזה בעצם מחלק אותם לרק"חים  
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
	int currentRoot;
	vector<int> colors(numVertices+1);
	init(colors);

	/*בכל פעם שהאלגוריתם מתחיל לייצר עץ, העץ מייצג רק"ח כלומר קדקוד בגרף העל.
	  נוסיף קדקוד זה למערך הקדקודים של גרף העל
		superGraph.addVertex(i);
	*/
	vector<int> rootsArr(numVertices+1);

	for (int u : mainLoop)
	{
		if (colors[u] == WHITE)
		{
			currentRoot = u;
			superGraph.addVertex(u);
			visitTreesDFS(u, currentRoot, rootsArr, colors, superGraph);
		}
	}
}

void Graph::visitTreesDFS(int u, int currentRoot, vector<int>& rootsArr ,
	vector<int>& colors, Graph& superGraph)
{
	list<int> neighbors = GetAdjList(u);
	rootsArr[u] = currentRoot;
	colors[u] = GRAY;

	for (int vertex : neighbors)
	{
		if (colors[vertex] == WHITE)
		{
			visitTreesDFS(vertex, currentRoot, rootsArr, colors, superGraph);
		}
		else if (rootsArr[vertex] != currentRoot)
		{
			if (!isAdjacentInSuperGraph(rootsArr[vertex], currentRoot))
			{
				superGraph.AddEdge(rootsArr[vertex], currentRoot);
			}
		}
	}

	colors[u] = BLACK;
}

//maybe DFS class and then no need to give parameters every time?
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
	int lastNeighborOfV = adjencyLists[v].getLastNeighborInList();
	bool res = lastNeighborOfV == u;
	return res;
}

void Graph::addVertex(int u)
{
	adjencyLists.push_back(Vertex(u));
	numVertices++;
}
