//Time:     2022/9/8
//Author:   YonkyG
//Describe: Leetcode Easy

#include<cstdio>
#include<string>
#include<queue>
#include<algorithm>

using namespace std;
 
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mi = prices[0], maxp = 0;
        for (int p : prices) {
            maxp = max(maxp, p - mi);
            mi = min(mi, p);
        }
        return maxp;
    }
};

int main() {
    Solution ss;
    vector<int> test = { 7,1,5,3,6,4 };
    printf("%d", ss.maxProfit(test));
    return 0;
}