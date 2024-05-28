#include "Vertex.h"
#include <algorithm>

int Vertex::GetVal()
{
	return value;
}

void Vertex::SetVal(int val)
{
	value = val;
}
list<int> Vertex::GetNeighbors()
{
	return neighbors;
}

bool Vertex::IsNeighbor(int v)
{
	//find(this->neighbors.begin(), this->neighbors.end(), v)
	for (int neighbor : neighbors)
	{
		if (neighbor == v)
		{
			return true;
		}
	}
	return false;
}
void Vertex::AddNeighbor(int v)
{
	//TO DO - check valid input
	this->neighbors.push_back(v);
}

void Vertex::RemoveNeighbor(int v)
{
	//TO DO - check valid input
	this->neighbors.remove(v);
}

int Vertex::getLastNeighborInList()
{
	return neighbors.back();
}

