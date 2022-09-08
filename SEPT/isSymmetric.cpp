//Time:     2022/9/8
//Author:   YonkyG
//Describe: Leetcode Easy

#include<cstdio>
#include<string>
#include<queue>
#include<algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
public:
    bool isSym(TreeNode* p, TreeNode* q) {
        if (!p && !q) return 1;
        else if (!p || !q) return 0;
        else return (p->val == q->val) && isSym(p->left, q->right) && isSym(p->right, q->left);
    }
    bool isSymmetric(TreeNode* root) {
        if (!root) return 1;
        else return isSym(root->left, root->right);
    }
};

int main() {
    return 0;
}