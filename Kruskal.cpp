#include<iostream>
#include<vector>
#include<algorithm>
#define SIZE 10
using namespace std;

class Edge {
public:
	int node[2];
	int distance;
	Edge(int a, int b, int distance) {
		this->node[0] = a;
		this->node[1] = b;
		this->distance = distance;
	}
	//define sort compare
	bool operator <(Edge edge) {
		return this->distance < edge.distance;
	}
};

//using union-find methods
int getParent(int parent[], int x) {
	if (parent[x] == x) return x;
	return parent[x] = getParent(parent, parent[x]);
}

void unionNodes(int parent[], int nodeA, int nodeB) {
	nodeA = getParent(parent, nodeA);
	nodeB = getParent(parent, nodeB);
	if (nodeA > nodeB) parent[nodeA] = nodeB;
	else parent[nodeB] = nodeA;
}

bool checkNodeUnion(int parent[], int nodeA, int nodeB) {
	nodeA = getParent(parent, nodeA);
	nodeB = getParent(parent, nodeB);
	if (nodeA == nodeB) return true;
	else return false;
}

void main() {
	int min_kruskal = 0;
	//static nodes
	int parent[SIZE + 1];
	for (int i = 1; i < SIZE + 1; i++)
		parent[i] = i;

	//edges
	vector<Edge> space;
	space.push_back(Edge(1, 4, 28));
	space.push_back(Edge(1, 7, 12));
	space.push_back(Edge(1, 5, 17));
	space.push_back(Edge(4, 2, 24));
	space.push_back(Edge(2, 5, 62));
	space.push_back(Edge(7, 4, 13));
	space.push_back(Edge(5, 6, 45));
	space.push_back(Edge(3, 5, 20));
	space.push_back(Edge(3, 6, 37));
	space.push_back(Edge(1, 2, 67));
	space.push_back(Edge(5, 7, 73));
	sort(space.begin(), space.end());

	//if node not in grape, union node. else continue
	for (int i = 0; i < space.size(); i++) {
		if (!checkNodeUnion(parent, space[i].node[0], space[i].node[1])) {
			unionNodes(parent, space[i].node[0], space[i].node[1]);
			min_kruskal += space[i].distance;
		}
	}
	cout << "Min value of union all nodes : " << min_kruskal << '\n';
}