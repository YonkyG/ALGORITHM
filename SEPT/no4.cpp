#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
vector<int> pre;
vector<int> in;
bool f;

struct Node {
	int data;
	Node* left, * right;
	Node(int d):data(d),left(0),right(0){}
};

Node* bt(int preL, int preR, int inL, int inR) {
	if (preR == preL) {
		Node* root = new Node(pre[preL]);
		return root;
	}
	int pivot = pre[preL], k = 0, flag = 0;
	for (int i = inL;i <= inR;i++) {
		if (in[i] == pivot) {
			k = i; flag = 1; break;
		}
	}
	//printf("%d %d %d %d\n", preL, preR, inL, inR);
	if (flag == 0) {
		f = 0; return 0;
	}
	int lenL = k - inL;
	Node* root = new Node(pivot);
	root->left = bt(preL + 1, preL + lenL, inL, k - 1);
	if (!f) return 0;
	root->right = bt(preL + lenL + 1, preR, k + 1, inR);
	if (!f) return 0;
	return root;
}

void post(Node* root) {
	if (!root) return;
	post(root->left);
	post(root->right);
	printf("%d ", root->data);
}

int main() {
	f = 1;
	int n, temp;
	scanf("%d", &n);
	for (int i = 0;i < n;i++) {
		scanf("%d", &temp);
		pre.push_back(temp);
	}
	for (int i = 0;i < n;i++) {
		scanf("%d", &temp);
		in.push_back(temp);
	}
	Node* root = bt(0, n - 1, 0, n - 1);
	if (!f) printf("No");
	else post(root);
	return 0;
}