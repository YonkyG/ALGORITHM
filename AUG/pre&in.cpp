//Time:     2022/8/30
//Author:   YonkyG
//Describe: ALGORITHM P295

#include<cstdio>
#include<algorithm>

using namespace std;

const int LEN = 3;
int pre[LEN] = { 1,2,3 };
int in[LEN] = { 2,1,3 };

struct Node {
	int data;
	Node* left, * right;
	Node(int d) :data(d), left(0), right(0) {}
};

Node* create(int preL, int preR, int inL, int inR) {
	if (preR < preL) return 0;
	Node* root = new Node(pre[preL]);
	int k = inL; //root in IN
	for (;k <= inR;k++) {
		if (in[k] == root->data) break;
	}
	int length = k - inL; //left tree
	root->left = create(preL + 1, preL + length, inL, k - 1);
	root->right = create(preL + length + 1, preR, k + 1, inR);
	return root;
}

void post(Node* root) {
	if (!root) return;
	post(root->left);
	post(root->right);
	printf("%d ", root->data);
}

int main() {
	Node* root = create(0, LEN - 1, 0, LEN - 1);
	post(root);
	return 0;
}