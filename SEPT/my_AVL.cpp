//Time:     2022/9/7
//Author:   YonkyG
//Describe: Review

#include<cstdio>
#include<algorithm>

using namespace std;

const int MAXN = 100;
int n = 7;
int nums[MAXN] = { 3,5,2,2,4,1,7 };

struct Node {
    int data, height;
    Node* left, * right;
    Node(int d) :data(d), height(0), left(0), right(0) {  }
};

int calHeight(Node* root) {
    if (!root) return 0;
    else return root->height;
}

int calBF(Node* root) {
    if (!root) return 0;
    else return calHeight(root->left) - calHeight(root->right);
}

void updHeight(Node* root) {
    root->height = max(calHeight(root->left), calHeight(root->right)) + 1;
}

void rightRot(Node*& root) {
    Node* lft = root->left;
    root->left = lft->right;
    lft->right = root;
    root = lft; //very tricky
}

void leftRot(Node*& root) {
    Node* rgt = root->right;
    root->right = rgt->left;
    rgt->left = root;
    root = rgt; //very tricky
}

void insert(int num, Node*& root) {
    if (!root) {
        root = new Node(num); return;
    }
    if (root->data == num) return;
    else if (root->data > num) {
        insert(num, root->left);
        updHeight(root); //very tricky, update upward
        if (calBF(root) == 2) {
            if (calBF(root->left) == 1) { //LL
                rightRot(root);
            }
            else { //LR
                leftRot(root->left);
                rightRot(root);
            }
        }
    }
    else {
        insert(num, root->right);
        updHeight(root); //very tricky, update upward
        if (calBF(root) == -2) {
            if (calBF(root->right) == -1) { //RR
                leftRot(root);
            }
            else { //RL
                rightRot(root->right);
                leftRot(root);
            }
        }
    }
}

int findMax(Node* root) {
    Node* p = root;
    while (p->right) p = p->right;
    return p->data;
}

int findMin(Node* root) {
    Node* p = root;
    while (p->left) p = p->left;
    return p->data;
}

void del(int x, Node*& root) {
    if (!root) return;
    if (root->data == x) {
        if (root->left) {
            root->data = findMax(root->left);
            del(root->data, root->left);
            updHeight(root);
            if (calBF(root) == -2) {
                if (calBF(root->right) == -1) { //RR
                    leftRot(root);
                }
                else { //RL
                    rightRot(root->right);
                    leftRot(root);
                }
            }
        }
        else if (root->right) {
            root->data = findMin(root->right);
            del(root->data, root->right);
            updHeight(root);
            if (calBF(root) == 2) {
                if (calBF(root->left) == 1) { //LL
                    rightRot(root);
                }
                else { //LR
                    leftRot(root->left);
                    rightRot(root);
                }
            }
        }
        else { //leaf
            delete(root); root = 0; return;
        }
    }
    else if (root->data > x) {
        del(x, root->left);
    }
    else {
        del(x, root->right);
    }
}

Node* create() {
    Node* root = 0;
    for (int i = 0;i < n;i++) {
        insert(nums[i], root);
    }
    return root;
}

void inOrder(Node* root) {
    if (!root) return;
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}

int main() {
    Node* root = create();
    del(2, root);
    del(7, root);
    del(2, root);
    inOrder(root);
    return 0;
}