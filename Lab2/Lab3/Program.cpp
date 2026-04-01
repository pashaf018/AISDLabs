#include "Includes.h"
#include "Graphs.h"

int main()
{
	Graphs graphs = Graphs();
	graphs.generateRandomList(5, 4);
	graphs.printAdjList();
}