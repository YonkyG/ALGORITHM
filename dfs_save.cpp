//Time:     2022/8/29
//Author:   YonkyG
//Describe: ALGORITHM P273

#include<cstdio>
#include<algorithm>

using namespace std;

const int MAXN = 100;

int n, k, sumN, maxSqu;
int nums[MAXN];
int temp[MAXN];
int ans[MAXN];

void dfs(int index, int cnt, int sum, int squ) {
	if (sum == sumN && cnt == k) {
		if (squ > maxSqu) { //save
			maxSqu = squ;
			for (int i = 0;i < n;i++) {
				ans[i] = temp[i];
			}
		}
		return;
	}
	if (index == n) return;
	if (sum + nums[index] <= sumN && cnt <= k) {
		temp[index] = 1; 
		dfs(index + 1, cnt + 1, sum + nums[index], squ + nums[index] * nums[index]); //yes
		temp[index] = 0; 
	}
	dfs(index + 1, cnt, sum, squ); //no
}

int main() {
	scanf("%d%d%d", &n, &sumN, &k);
	maxSqu = 0;
	for (int i = 0;i < n;i++) {
		scanf("%d", &nums[i]);
	}
	dfs(0, 0, 0, 0);
	for (int i = 0;i < n;i++) {
		if (ans[i]) printf("%d ", nums[i]);
	}
	printf("\nans = %d\n", maxSqu);
	return 0;
}