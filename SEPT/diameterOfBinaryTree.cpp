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
    int m;
    int depth(TreeNode* root) {
        if (!root) return 0;
        int dL = depth(root->left);
        int dR = depth(root->right);
        m = max(m,  dL + dR);
        return max(dL, dR) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        depth(root);
        return m;
    }
    Solution():m(0){}
};

int main() {
    Solution ss;
    return 0;
}