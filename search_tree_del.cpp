//Time:     2022/8/31
//Author:   YonkyG
//Describe: ALGORITHM P314

#include<cstdio>
#include<algorithm>

using namespace std;

const int LEN = 10;

struct Node {
	int data;
	Node* left, * right;
	Node(int x) :data(x), left(0), right(0) {  }
};

void insert(Node*& root, int x) {
	if (!root) {
		root = new Node(x); return;
	}
	if (root->data == x) return;
	else if (root->data > x) insert(root->left, x);
	else insert(root->right, x);
}

Node* findMax(Node* root) { //left
	while (root->right) root = root->right;
	return root;
}

Node* findMin(Node* root) { //right
	while (root->left) root = root->left;
	return root;
}

void deleteNode(Node*& root, int x) {
	if (!root) return;
	if (root->data == x) {
		if (!root->left && !root->right) {
			delete root;
			root = 0;//delete leaf node
		}
		else if (root->left) {
			Node* m = findMax(root->left);
			root->data = m->data;
			deleteNode(root->left, m->data); //root->left, not m, which isn't in tree
		}
		else {
			Node* m = findMin(root->right);
			root->data = m->data;
			deleteNode(root->right, m->data);
		}
	}
	else if (root->data > x) deleteNode(root->left, x);
	else deleteNode(root->right, x);
}

void inOrder(Node* root) {
	if (!root) return;
	inOrder(root->left);
	printf("%d ", root->data);
	inOrder(root->right);
}

void preOrder(Node* root) {
	if (!root) return;
	printf("%d ", root->data);
	preOrder(root->left);
	preOrder(root->right);
}

int main() {
	int numbers[LEN] = { 7,2,3,5,0,8,9,6,1,4 };
	Node* root = 0;
	for (int i = 0;i < LEN;i++) {
		insert(root, numbers[i]);
	}
	inOrder(root);
	printf("\n---------\n");
	deleteNode(root, 7);
	preOrder(root);
	return 0;
}