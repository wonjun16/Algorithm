#include<iostream>
#include<vector>
#include<queue>
#define SIZE 7
using namespace std;

void bfs(int start, bool check[], vector<int> data[]) {
	queue<int> q;
	q.push(start);
	check[start] = true;
	while (!q.empty()) {
		int dataEx = q.front();
		cout << dataEx << ' ';
		q.pop();
		for (int i = 0; i < data[dataEx].size(); i++) {
			if (!check[data[dataEx][i]]) {
				check[data[dataEx][i]] = true;
				q.push(data[dataEx][i]);
			}
		}
	}
}

void main() {
	vector<int> data[SIZE+1];
	bool check[SIZE + 1] = { false };
	data[1].push_back(2);
	data[2].push_back(1);

	data[1].push_back(3);
	data[3].push_back(1);

	data[2].push_back(3);
	data[3].push_back(2);

	data[2].push_back(4);
	data[4].push_back(2);

	data[2].push_back(5);
	data[5].push_back(2);

	data[3].push_back(6);
	data[6].push_back(3);

	data[3].push_back(7);
	data[7].push_back(3);

	data[4].push_back(5);
	data[5].push_back(4);

	data[6].push_back(7);
	data[7].push_back(6);

	bfs(1, check, data);
}