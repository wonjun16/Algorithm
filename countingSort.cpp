#include<iostream>
#define SIZE 30
#define MAX_NUM 5

void countingSort(int* data) {
	int index=0;
	int count[MAX_NUM + 1] = { 0 };
	for (int i = 0; i < SIZE; i++)
		count[data[i]]++;
	for (int j = 1; j < MAX_NUM+1;j++) {
		for (int k = 0; k < count[j]; k++) {
			data[index] = j;
			index++;
		}
	}
}

void main() {
	int data[SIZE] = {
		1, 4, 5, 3, 2, 1, 3, 4, 2, 5,
		3, 4, 2, 5, 3, 2, 1, 2, 3, 4, 
		4, 3, 2, 1, 5, 5, 4, 3, 2, 1
	};
	countingSort(data);
	for (int i = 0; i < SIZE; i++)
		std::cout << data[i] << ' ';
}