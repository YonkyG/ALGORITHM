//Time:     2022/8/30
//Author:   YonkyG
//Describe: ALGORITHM P295

#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

const int LEN = 7;
int in[LEN] = { 1,2,3,4,5,6,7 };

struct Node {
	int data;
	Node* left, * right;
	Node(int d) :data(d), left(0), right(0) {}
};

Node* create(const vector<int>& nlayer, int inL, int inR) {
	if (nlayer.empty()) return 0;
	Node* root = new Node(nlayer.front());
	int k = inL; //root in IN
	for (;k <= inR;k++) {
		if (in[k] == root->data) break;
	}
	vector<int> leftLay;
	vector<int> rightLay;
	for (int i = 1;i < nlayer.size();i++) {
		int num = nlayer[i];
		bool lft = 0; //num is in left
		for (int j = inL;j < k;j++) {
			if (num == in[j]) {
				leftLay.push_back(num);
				lft = 1; break;
			}
		}
		if (!lft) rightLay.push_back(num);
	}
	root->left = create(leftLay, inL, k - 1);
	root->right = create(rightLay, k + 1, inR);
	return root;
}

void preorder(Node* root) {
	if (!root) return;
	printf("%d ", root->data);
	preorder(root->left);
	preorder(root->right);
}

int main() {
	vector<int> layer = { 4,1,6,3,5,7,2 };
	Node* root = create(layer, 0, LEN - 1);
	preorder(root);
	return 0;
}