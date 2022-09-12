//Time:     2022/9/12
//Author:   YonkyG
//Describe: Leetcode Medium

#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

void print(vector<int>& nums) {
    for (int num : nums) printf("%d ", num);
    printf("\n--------------\n");
}
 
class Solution {
public:
    void rvs(vector<int>& nums, int low, int high) {
        while (low < high) swap(nums[low++], nums[high--]);
    }
    void nextPermutation(vector<int>& nums) {
        int flag = -1, n = nums.size(), swp = -1;
        for (int i = n - 1;i > 0;i--) {
            if (nums[i] > nums[i - 1]) {
                flag = i - 1; break;
            }
        }
        if (flag == -1) {
            rvs(nums, 0, n - 1);
            return;
        }
        for (int i = n - 1;i > flag;i--) {
            if (nums[i] > nums[flag]) {
                swp = i; break;
            }
        }
        swap(nums[flag], nums[swp]);
        rvs(nums, flag + 1, n - 1);
    }
};

int main() {
    Solution ss;
    vector<int> nums = { 1,2,3 };
    ss.nextPermutation(nums);
    print(nums);
    return 0;
}