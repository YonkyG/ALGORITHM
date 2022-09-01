//Time:     2022/8/31
//Author:   YonkyG
//Describe: ALGORITHM P327

#include<cstdio>
#include<algorithm>

using namespace std;

const int LEN = 10;

struct Node {
	int data, height;
	Node* left, * right;
	Node(int x) :data(x), height(1), left(0), right(0) {  }
};

int getHeight(Node* root) {
	if (!root) return 0;
	else return root->height;
}

int getBF(Node* root) {
	return getHeight(root->left) - getHeight(root->right);
}

void updHeight(Node* root) {
	root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
}

void leftRot(Node*& root) {
	Node* temp = root->right;
	root->right = temp->left;
	temp->left = root;
	updHeight(root);
	updHeight(temp);
	root = temp; //modify Node*
}

void rightRot(Node*& root) {
	Node* temp = root->left;
	root->left = temp->right;
	temp->right = root;
	updHeight(root);
	updHeight(temp);
	root = temp; //modify Node*
}

void insert(Node*& root, int x) {
	if (!root) {
		root = new Node(x);
		return;
	}
	if (root->data == x) return;
	else if (root->data > x) {
		insert(root->left, x);
		updHeight(root);
		if (getBF(root) == 2) {
			if (getBF(root->left) == -1) { //LR
				printf("LR: %d\n", root->data);
				leftRot(root->left);
				rightRot(root);
			}
			else { //LL
				printf("LL: %d\n", root->data);
				rightRot(root);
			}
		}
	}
	else {
		insert(root->right, x);
		updHeight(root);
		if (getBF(root) == -2) {
			if (getBF(root->right) == 1) { //RL
				printf("RL: %d\n", root->data);
				rightRot(root->right);
				leftRot(root);
			}
			else { //RR
				printf("RR: %d\n", root->data);
				leftRot(root);
			}
		}
	}
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
	int numbers[LEN] = { 7,2,3,5,0,8,9,6,4,10 };
	Node* root = 0;
	for (int i = 0;i < LEN;i++) {
		//printf("%d ", numbers[i]);
		insert(root, numbers[i]);
	}
	printf("\n");
	preOrder(root);
	printf("\n");
	inOrder(root);
	return 0;
}