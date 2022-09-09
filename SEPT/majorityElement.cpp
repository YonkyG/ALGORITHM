//Time:     2022/9/9
//Author:   YonkyG
//Describe: Leetcode Easy

#include<cstdio>
#include<map>
#include<algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

 
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> ht;
        int ans = 0;
        for (int n : nums) {
            ht[n]++;
            if (ht[n] > ht[ans]) ans = n;
        }
        return ans;
    }
    int majorityElement_plus(vector<int>& nums) {
        int ele = nums[0], cnt = 0;
        for (int n : nums) {
            if (cnt == 0) ele = n;
            if (ele == n) cnt++;
            else cnt--;
        }
        return ele;
    }
};

int main() {
    
    return 0;
}