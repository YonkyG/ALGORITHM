//Time:     2022/8/29
//Author:   YonkyG
//Describe: ALGORITHM P271

#include<cstdio>
#include<algorithm>

using namespace std;

const int MAXN = 100;
const int MAXV = 8; //capacity

int dfs(int index, int sumW, int sumC, const int w[], const int c[], int n) {
	if (index == n) return sumC;
	int no = dfs(index + 1, sumW, sumC, w, c, n);
	int yes = 0;
	if (sumW + w[index] <= MAXV) {
		yes = dfs(index + 1, sumW + w[index], sumC + c[index], w, c, n);
	}
	return no > yes ? no : yes;
}

int main() {
	const int w[MAXN] = { 3,5,1,2,2 };
	const int c[MAXN] = { 4,5,2,1,3 };
	int n = 5;
	int ans = dfs(0, 0, 0, w, c, n);
	printf("ans = %d\n", ans);
	return 0;
}