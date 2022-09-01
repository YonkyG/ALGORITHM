//Time:     2022/8/23
//Author:   YonkyG
//Describe: ALGORITHM P116

#include<cstdio>
#include<algorithm>

const int MAXN = 50;

class Solution {
public:
	void fullPermutation(int index, int n, int table[], int ans[], int& num) {
		if (index == n + 1) {
			num++; return;
		}
		for (int i = 1;i <= n;i++) {
			if (!table[i]) {
				bool flag = 0;
				for (int pre = 1;pre < index;pre++) {
					if (abs(index - pre) == abs(i - ans[pre])) {
						flag = 1; break;
					}
				}
				if (!flag) {
					ans[index] = i;
					table[i] = 1, index++;
					fullPermutation(index, n, table, ans, num);
					table[i] = 0, index--;
				}
			}
		}
		return;
	}
};

int main() {
	int table[MAXN] = { 0 };
	int ans[MAXN] = { 0 };
	int n, index = 0, num = 0;
	scanf("%d", &n);
	Solution ss;
	ss.fullPermutation(1, n, table, ans, num);
	printf("%d Queens has %d solutions.\n", n, num);
	return 0;
}