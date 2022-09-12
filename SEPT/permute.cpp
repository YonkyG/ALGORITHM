//Time:     2022/9/12
//Author:   YonkyG
//Describe: Leetcode Medium

#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;
 
class Solution {
public:
    vector<vector<int>> ans;
    vector<bool> flag;
    vector<int> p;
    int n;
    void init(int n) {
        for (int i = 0;i < n;i++) {
            flag.push_back(0);
            p.push_back(0);
        }
    }
    void helper(vector<int>& nums, int cnt) {
        if (cnt >= n) {
            ans.push_back(p);
            return;
        }
        for (int i = 0;i < n;i++) {
            if (!flag[i]) {
                flag[i] = 1;
                p[cnt] = nums[i];
                helper(nums, cnt + 1);
                flag[i] = 0;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        init(n);
        if (n) helper(nums, 0);
        return ans;
    }
};

int main() {
    Solution ss;
    vector<int> nums = { 5,3,1 };
    vector<vector<int>> ans = ss.permute(nums);
    for (int i = 0;i < ans.size();i++) {
        for (int j = 0;j < ans[i].size();j++) {
            printf("%d ", ans[i][j]);
        }
        printf("\n");
    }
    return 0;
}