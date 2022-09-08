//Time:     2022/9/8
//Author:   YonkyG
//Describe: Leetcode Easy

#include<cstdio>
#include<vector>
#include<stack>
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        TreeNode* p = root;
        if (!p) return v;
        stack<TreeNode*> s;
        bool vis = 0;
        while (1) {
            if (!vis) {
                while (p->left) {
                    s.push(p);
                    p = p->left;
                }
            }
            v.push_back(p->val);
            if (p->right) {
                p = p->right; vis = 0;
            }
            else {
                if (s.empty()) break;
                p = s.top(); s.pop(); vis = 1;
            }
        }
        return v;
    }
};

int main() {
    
    return 0;
}