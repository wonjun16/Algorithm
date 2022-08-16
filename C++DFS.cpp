#include<iostream>
#include<vector>
#define SIZE 7
using namespace std;

void dfs(int index, int check[], vector<int> data[]) {
	if (check[index]) return;
	check[index] = true;
	cout << index << ' ';
	for (int i = 0; i < data[index].size(); i++) {
		if (!check[data[index][i]])
			dfs(data[index][i], check, data);
	}
}

void main() {
	vector<int> data[SIZE + 1];
	int check[SIZE + 1] = { 0 };
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

	dfs(1, check, data);
}