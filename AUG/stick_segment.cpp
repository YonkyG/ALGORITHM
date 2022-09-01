//Time:     2022/8/26
//Author:   YonkyG
//Describe: ALGORITHM P134

#include<cstdio>
#include<algorithm>
using namespace std;

const int MAXN = 10;

int main() {
	int n, num; //num > n
	scanf("%d%d", &n, &num);
	int len[MAXN] = { 0 };
	int mini = INT_MAX;
	for (int i = 0;i < n;i++) {
		scanf("%d", &len[i]);
		if (len[i] < mini) mini = len[i];
	}
	int low = 0, high = mini;
	int mlen = 0;
	while (low < high) {
		mlen = low + (high - low) / 2;
		printf("low = %d mid = %d high = %d\n", low, mlen, high);
		int cnt = 0;
		for (int i = 0;i < n;i++) {
			cnt += len[i] / mlen;
		}
		if (cnt < num) high = mlen;
		else low = mlen + 1;
	}
	printf("Max length = %d\n", high - 1);
	return 0;
}