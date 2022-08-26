#include<iostream>
#include<vector>
#include<queue>
#define SIZE 7
using namespace std;

vector<int> grape[SIZE] = {
	{0}, {2, 5}, {3}, {4}, {6}, {6}, {7}
};
int result[SIZE];
int entryLevel[SIZE+1] = { -1, 0, 1, 1, 1, 1, 2, 1 };

void topologySort() {
	int node;
	queue <int>q;
	//1. if entry level==0, push to queue
	for (int i = 0; i < SIZE; i++) {
		if (!entryLevel[i])
			q.push(i);
	}
	
	for (int i = 0; i < SIZE; i++) {
		//2. queue is empty when before visited all nodes > cycle > return
		if (q.empty()) {
			cout << "Cycle appeared. Can't maintain topology sort";
			return;
		}
		//3. pop one node in queue and delete it's all branch
		node = q.front();
		q.pop();
		result[i] = node;
		//4. push to queue if node's entry level==0
		for (int j = 0; j < grape[node].size(); j++) {
			if (!--entryLevel[grape[node][j]])
				q.push(grape[node][j]);
		}
	}

	for (int k = 0; k < SIZE; k++)
		cout << result[k]<<' ';
}

void main() {
	topologySort();
}