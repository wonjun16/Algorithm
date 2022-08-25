#include<iostream>
#define SIZE 4
#define INF 1000000

int grape[SIZE][SIZE] = {
	{0, 5, INF, 8},
	{7, 0, 9, INF},
	{2, INF, 0, 4},
	{INF, INF, 3, 0}
};

void floydWarshall() {
	int result[SIZE][SIZE];
	for(int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++)
			result[i][j] = grape[i][j];
	}

	//i : node that go through
	for (int i = 0; i < SIZE; i++) {
		//j : start node
		for (int j = 0; j < SIZE; j++) {
			//k : arrival node
			for (int k = 0; k < SIZE; k++) {
				if (result[j][k] > result[j][i] + result[i][k])
					result[j][k] = result[j][i] + result[i][k];
			}
		}
	}

	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++)
			std::cout << result[i][j] << ' ';
		std::cout << '\n';
	}
}

void main() {
	floydWarshall();
}