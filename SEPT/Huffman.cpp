//Time:     2022/9/1
//Author:   YonkyG
//Describe: ALGORITHM P344

#include<cstdio>
#include<queue>
#include<algorithm>

using namespace std;

const int MAXN = 100;
priority_queue<int, vector<int>, greater<int>> q;

int main() {
	int n, temp;
	scanf("%d", &n);
	for (int i = 0;i < n;i++) {
		scanf("%d", &temp);
		q.push(temp);
	}
	int ans = 0, a, b;
	while (q.size() > 1) {
		a = q.top();
		q.pop();
		b = q.top();
		q.pop();
		ans += (a + b);
		q.push(a + b);
	}
	printf("ans = %d", ans);
	return 0;
}
