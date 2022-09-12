//Time:     2022/9/11
//Author:   YonkyG
//Describe: Leetcode Medium

#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;
 
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size() - 1; //bound
        int half = (n + 2) / 2, _half = (n + 1) / 2;
        int temp;
        for (int i = 0;i < half;i++) {
            for (int j = 0;j < _half;j++) {
                temp = matrix[i][j];
                swap(temp, matrix[j][n - i]);
                swap(temp, matrix[n - i][n - j]);
                swap(temp, matrix[n - j][i]);
                swap(temp, matrix[i][j]);
            }
        }
    }
};

int main() {
    vector<vector<int>> matrix = { {1, 2, 3},{4, 5, 6},{7, 8, 9} };
    Solution ss;
    ss.rotate(matrix);
    int n = matrix.size();
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}