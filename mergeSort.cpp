#include<iostream>
#define SIZE 7

int mergeSpace[SIZE];

void merge(int *data, int start, int middle, int end) {
	int i=start, j=middle+1, t=start;
	while (i <= middle && j <= end) {
		if (data[i] >= data[j]) {
			mergeSpace[t] = data[j];
			j++;
		}
		else {
			mergeSpace[t] = data[i];
			i++;
		}
		t++;
	}
	if (i > middle) {
		for (t; t <= end; t++) {
			mergeSpace[t] = data[j];
			j++;
		}
	}
	else {
		for (t; t <= end; t++) {
			mergeSpace[t] = data[i];
			i++;
		}
	}
	for (int k = start; k <= end; k++) {
		data[k] = mergeSpace[k];	
	}
}

void mergeSort(int *data, int start, int end) {
	if (end > start) {
		int middle = (start + end) / 2;
		mergeSort(data, start, middle);
		mergeSort(data, middle + 1, end);
		merge(data, start, middle, end);
	}
}

void main() {
	int data[SIZE] = { 7, 6, 5, 8, 3, 5, 9 }; 
	mergeSort(data, 0, SIZE - 1);
	for (int i = 0; i < SIZE; i++)
		std::cout << data[i] << " ";
}