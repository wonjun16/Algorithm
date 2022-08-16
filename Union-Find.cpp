#include<iostream>
#define SIZE 7

//find parent of node
int getParent(int parent[], int child) {
	if (parent[child] == child) return child;
	return parent[child] = getParent(parent, parent[child]);
}

//union two nodes (smaller > parent / bigger > child)
void unionParent(int parent[], int nodeA, int nodeB) {
	nodeA = getParent(parent, nodeA);
	nodeB = getParent(parent, nodeB);
	if (nodeA > nodeB) parent[nodeA] = nodeB;
	else parent[nodeB] = nodeA;
}

//distinguish if two nodes are linked
bool check(int nodeA, int nodeB, int parent[]) {
	if (getParent(parent, nodeA) == getParent(parent, nodeB))return true;
	else return false;
}

void main() {
	int parent[SIZE + 1];
	//initialize all nodes
	for (int i = 1; i < SIZE + 1; i++)
		parent[i] = i;
	unionParent(parent, 1, 2);
	unionParent(parent, 2, 3);
	unionParent(parent, 3, 4);
	unionParent(parent, 5, 6);
	unionParent(parent, 6, 7);
	unionParent(parent, 1, 6);

	std::cout << "node1 and node5 are linked : " << check(1, 5, parent) << '\n';
	std::cout << "node6 and node7 are linked : " << check(6, 7, parent) << '\n';
}