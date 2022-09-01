//Time:     2022/9/1
//Author:   YonkyG
//Describe: ALGORITHM P334

#include<cstdio>
#include<algorithm>

using namespace std;

const int MAXN = 10;
int fat[MAXN] = { 0 };

int find(int x) {
	int a = x; //set root
	while (fat[a] != a) { //find
		a = fat[a];
	}
	while (fat[x] != a) { //path compress
		int f = fat[x];
		fat[x] = a;
		x = f;
	}
	return a;
}

void insert(int x, int y) {
	fat[find(x)] = find(y);
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1;i <= n;i++) {
		fat[i] = i;
	}
	for (int i = 0;i < m;i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		insert(a, b);
	}
	int roots[MAXN] = { 0 };
	for (int i = 1;i <= n;i++) {
		roots[find(i)]++;
		printf("%d belongs to %d\n", i, find(i));
	}
	int ans = 0; //num of sets
	for (int i = 1;i <= n;i++) {
		if (roots[i]) {
			printf("Set %d has %d numbers\n", i, roots[i]);
			ans++;
		}
	}
	printf("Num of sets = %d\n", ans);
	return 0;
}
/*7 5
1 2
2 3
3 1
1 4
5 6*/