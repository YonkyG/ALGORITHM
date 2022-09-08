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
    bool isSymmetric(TreeNode* root) {
        if (!root) return 1;
        queue<TreeNode*> layer;
        layer.push(root->left);
        layer.push(root->right);
        while (!layer.empty()) {
            TreeNode* p = layer.front(); layer.pop();
            TreeNode* q = layer.front(); layer.pop();
            if (!p && !q) continue;
            if (!p || !q) return 0;
            if (p->val != q->val) return 0;
            layer.push(p->left); layer.push(q->right);
            layer.push(p->right); layer.push(q->left);
        }
        return 1;
    }
};

int main() {
    return 0;
}