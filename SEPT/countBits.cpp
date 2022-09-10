//Time:     2022/9/10
//Author:   YonkyG
//Describe: Leetcode Easy

#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;
 
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> v;
        v.push_back(0);
        for (int c = 1;c <= n;c *= 2) {
            for (int i = 0;i < c && c + i <= n;i++) {
                v.push_back(v[i] + 1);
            }
        }
        return v;
    }
};

int main() {
    Solution ss;
    vector<int> v = ss.countBits(10);
    return 0;
}