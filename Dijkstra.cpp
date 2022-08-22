#include<iostream>
#define SIZE 6
#define INF 1000000

//grape
int grape[SIZE][SIZE] = {
	{0, 2, 5, 1, INF, INF},
	{2, 0, 3, 2, INF, INF},
	{5, 3, 0, 3, 1, 5},
	{1, 2, 3, 0, 1, INF},
	{INF, INF, 1, 1, 0, 2},
	{INF, INF, 5, INF, 2, 0}
};
bool v[SIZE]; //visited node
int d[SIZE]; //distance(cost)

//return smallest distance from start node
int getSmallD() {
	int min = INF;
	int index=0;
	for (int i = 0; i < SIZE; i++) {
		if (d[i] < min && !v[i]) {
			index = i;
			min = d[i];
		}
	}
	return index;
}

void dijkstra(int start) {
	for (int i = 0; i < SIZE; i++)
		v[i] = 0;
	v[start] = 1;
	for (int i = 0; i < SIZE; i++) {
		d[i] = grape[start][i];
	}
	for (int i = 0; i < SIZE - 2; i++) { // -start, -end index
		int sIndex = getSmallD();
		v[sIndex] = 1;
		for (int j = 0; j < SIZE; j++) {
			if (!v[j]) {
				if (d[j] > grape[sIndex][j] + d[sIndex])
					d[j] = grape[sIndex][j] + d[sIndex];
			}
		}
	}
}
void main() {
	for (int i = 0; i < SIZE; i++) {
		dijkstra(i);
		std::cout << "dijstra of node" << i + 1 << ": ";
		for (int j = 0; j < SIZE; j++)
			std::cout << d[j] << ' ';
		std::cout << '\n';
	}
}