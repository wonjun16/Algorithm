#include<iostream>
#define SIZE 100000
int number[SIZE+1];

void sieve() {
	for (int i = 1; i < SIZE + 1; i++)
		number[i] = i;
	for (int i = 2; i * i < SIZE + 1; i++) {
		if (number[i]) {
			for (int j = i + i; j < SIZE + 1; j+=i) {
				if (!(number[j] % i)) number[j] = 0;
			}
		}
	}
	for (int i = 2; i < SIZE + 1; i++) {
		if (number[i]) std::cout << number[i] << ' ';
	}
}

void main() {
	sieve();
}