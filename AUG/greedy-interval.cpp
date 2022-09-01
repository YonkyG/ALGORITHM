//Time:     2022/8/23
//Author:   YonkyG
//Describe: ALGORITHM P123

#include<cstdio>
#include<algorithm>
using namespace std;

const int MAXN = 10;

struct Interval {
	int x, y;
	Interval() :x(0), y(0) {}
};

bool cmp(const Interval& i1, const Interval& i2) {
	return i1.x > i2.x;
}

int main() {
	int n;
	scanf("%d", &n);
	Interval ins[MAXN];
	for (int i = 0;i < n;i++) {
		scanf("%d%d", &ins[i].x, &ins[i].y);
	}
	sort(ins, ins + n, cmp);
	int temp = ins[0].x;
	int ans = 1;
	for (int i = 1;i < n;i++) {
		if (ins[i].y <= temp) {
			temp = ins[i].x; ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}