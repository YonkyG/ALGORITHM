#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;

int main() {
	int n, k, temp;
	bool flag = 1;
	scanf("%d%d", &n, &k);
	vector<int> v;
	for (int i = 0;i <= k;i++) {
		scanf("%d", &temp);
		v.push_back(temp);
	}
	int oil = n, cnt = 0;
	for (int i = 0;i <= k;i++) {
		if (v[i] > n) {
			flag = 0; break;
		}
		if (v[i] > oil) {
			oil = n; cnt++;
		}
		oil -= v[i];
	}
	if (flag) printf("%d", cnt);
	else printf("No Solution");
	return 0;
}