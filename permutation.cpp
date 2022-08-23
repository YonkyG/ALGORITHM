//Time:     2022/8/23
//Author:   YonkyG
//Describe: ALGORITHM P115

#include<cstdio>

const int MAXN = 50;

class Solution {
public:
	void fullPermutation(int index, int n, int table[], int ans[]) {
		if (index == n + 1) {
			for (int i = 1;i <= n;i++) {
				printf("%d", ans[i]);
			}
			printf("\n");
			return;
		}
		for (int i = 1;i <= n;i++) {
			if (!table[i]) {
				ans[index] = i;
				table[i] = 1, index++;
				fullPermutation(index, n, table, ans);
				table[i] = 0, index--;
			}
		}
		return;
	}
};

int main() {
	int table[MAXN] = { 0 };
	int ans[MAXN] = { 0 };
	int n, index = 0;
	scanf("%d", &n);
	Solution ss;
	ss.fullPermutation(1, n, table, ans);
	return 0;
}