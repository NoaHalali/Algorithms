#ifndef  __VERTEX_H
#define __VERTEX_H
using namespace std;

#include <list> 
class Vertex
{
	int value;
	list<int> neighbors;

public:
	Vertex() {}
	Vertex(int _value) { value = _value; }
	int GetVal();
	void SetVal(int val);
	list<int> GetNeighbors();
	void AddNeighbor(int v);
	void RemoveNeighbor(int v);
	bool IsNeighbor(int v);
	int getLastNeighborInList();
	bool isEmptyNeighborsList();
};

#endif // ! 
