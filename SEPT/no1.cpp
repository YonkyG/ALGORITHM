#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;

int isUgly(int num) {
	bool flag = 1;
	while (flag) {
		flag = 0;
		if (num % 2 == 0) {
			num /= 2; flag = 1;
		}
		if (num % 3 == 0) {
			num /= 3; flag = 1;
		}
		if (num % 5 == 0) {
			num /= 5; flag = 1;
		}
	}
	if (num == 1) return 1;
	else return 0;
}

int main() {
	vector<int> v;
	int n, temp;
	scanf("%d", &n);
	for (int i = 0;i < n;i++) {
		scanf("%d", &temp);
		v.push_back(isUgly(temp));
	}
	for (int i = 0;i < n;i++) {
		printf("%d", v[i]);
	}
	return 0;
}