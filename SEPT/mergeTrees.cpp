//Time:     2022/9/11
//Author:   YonkyG
//Describe: Leetcode Easy

#include<cstdio>
#include<vector>
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
    TreeNode* copy(TreeNode* src) {
        if (!src) return 0;
        TreeNode* root = new TreeNode(src->val);
        root->left = copy(src->left);
        root->right = copy(src->right);
        return root;
    }
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (!root2) return copy(root1);
        if (!root1) return copy(root2);
        TreeNode* root = new TreeNode(root1->val + root2->val);
        root->left = mergeTrees(root1->left, root2->left);
        root->right = mergeTrees(root1->right, root2->right);
        return root;
    }
};

int main() {
    Solution ss;
    return 0;
}