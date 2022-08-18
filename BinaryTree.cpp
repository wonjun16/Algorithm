//Binary tree with traversal
#include<iostream>
#define SIZE 15
using namespace std;

typedef struct node* treePtr;
typedef struct node {
	int data;
	treePtr leftChild, rightChild;
}node;

void preorder(treePtr ptr) {
	if (ptr == NULL)return;
	cout << ptr->data << ' ';
	preorder(ptr->leftChild);
	preorder(ptr->rightChild);
}

void inorder(treePtr ptr) {
	if (ptr == NULL)return;
	inorder(ptr->leftChild);
	cout << ptr->data << ' ';
	inorder(ptr->rightChild);
}

void postorder(treePtr ptr) {
	if (ptr == NULL)return;
	postorder(ptr->leftChild);
	postorder(ptr->rightChild);
	cout << ptr->data << ' ';
}

int main() {
	//create tree
	node tree[SIZE];
	for (int i = 0; i < SIZE; i++) {
		tree[i].data = i + 1;
		tree[i].leftChild = NULL;
		tree[i].rightChild = NULL;
	}

	//linking tree to perfect binary tree
	for (int i = 0; i < SIZE; i++) {
		if(i==1)
			tree[0].leftChild = tree + i;
		else if (i % 2==0 && i>1)
			tree[(i / 2) - 1].rightChild = tree + i;
		else 
			tree[i / 2].leftChild = tree + i;
	}

	cout << "preorder : ";
	preorder(tree); cout << '\n';
	cout << "inorder : ";
	inorder(tree); cout << '\n';
	cout << "postorder : ";
	postorder(tree); cout << '\n';
	return 0;
}