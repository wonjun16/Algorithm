#include<iostream>
#define SIZE 10

void heapify(int* data, int start, int end) { //max heap상태로 만듦 start, end는 모두 data의 index
	int child=end, parent=child/2, temp, swap;
	if (start >= end)
		return;
	else {
		do {
			if (child % 2 == 0 && child!=end) {
				temp = data[child] >= data[child + 1] ? child : child+1;
			}
			else if(child!=end){
				temp = data[child] >= data[child - 1] ? child : child-1;
			}
			else {
				temp = child;
			}
			if (data[temp] > data[parent]) {
				swap = data[parent];
				data[parent] = data[temp];
				data[temp] = swap;
			}
			child --;
			parent = child / 2;
		} while (child != start);
	}

}

void heapSort(int* data, int start, int end) {
	int temp;
	for (int i = end; i > start; i--) {
		heapify(data, start, i);
		temp = data[i];
		data[i] = data[start];
		data[start] = temp;
	}
}

void main() {
	int data[SIZE] = { 6, 8, 5, 1, 5, 7, 2, 9, 10, 4 };
	heapSort(data, 0, SIZE-1);
	for (int i = 0; i < SIZE; i++)
		std::cout << data[i] << ' ';
}