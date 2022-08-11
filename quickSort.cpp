#include<iostream>
#define SIZE 15

void quickSort(int *data, int start, int end) {
	int pivot, i, j, temp;
	if (start >= end)
		return;
	else {
		pivot = data[start];
		i = start + 1;
		j = end;
		while (i <= j) {
			while (data[i] <= pivot)
				i++;
			while (data[j] >= pivot && j>start)
				j--;
			if (i < j) {
				temp = data[i];
				data[i] = data[j];
				data[j] = temp;
			}
			else {
				temp = pivot;
				data[start] = data[j];
				data[j] = temp;
			}
		}
		quickSort(data, start, j - 1);
		quickSort(data, j + 1, end);
	}
	
}

void main() {
	int data[SIZE] = { 5, 9, 6, 7, 8, 3, 2, 10, 1, 4 , 6, 7, 5, 4, 3};
	quickSort(data, 0, SIZE-1);
	for (int i = 0; i < SIZE; i++)
		std::cout << data[i] << " ";
}