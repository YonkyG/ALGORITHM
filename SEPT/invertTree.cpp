//Time:     2022/9/9
//Author:   YonkyG
//Describe: Leetcode Easy

#include<cstdio>
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
    void invert(TreeNode* root) {
        if (!root) return;
        invert(root->left);
        invert(root->right);
        swap(root->left, root->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        invert(root);
        return root;
    }
    TreeNode* invertTree_plus(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* p = q.front();
            q.pop();
            swap(p->left, p->right);
            if (p->left) q.push(p->left);
            if (p->right) q.push(p->right);
        }
        return root;
    }
};

int main() {
    
    return 0;
}