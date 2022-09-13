//Time:     2022/9/13
//Author:   YonkyG
//Describe: Leetcode Medium

#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;
 
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int nx = grid.size();
        int ny = grid[0].size();
        auto dp = vector<vector<int>>(nx, vector<int>(ny));
        dp[0][0] = grid[0][0];
        for (int i = 1;i < nx;i++) {
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }
        for (int i = 1;i < ny;i++) {
            dp[0][i] = dp[0][i - 1] + grid[0][i];
        }
        for (int i = 1;i < nx;i++) {
            for (int j = 1;j < ny;j++) {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }
        return dp[nx - 1][ny - 1];
    }
};

int main() {
    Solution ss;
    vector<vector<int>>  a = { {1, 3, 1},{1, 5, 1} };
    printf("%d", ss.minPathSum(a));
    return 0;
}