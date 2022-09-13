#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;

int count(string s) {
	int cnt = 0;
	if (s.size() < 4) return 0;
	for (int i = 0;i <= s.size() - 4;i++) {
		if (s[i] == '1' && s[i+1] == '9' && s[i+2] == '2' && s[i+3] == '3')
			cnt++;
	}
	return cnt;
}

int main() {
	string s;
	cin >> s;
	int cnt = count(s);
	printf("%d ", cnt);
	if (cnt == 0 || cnt == 1 || cnt == 2) {
		printf("Yes");
	}
	else {
		int flag = 0;
		for (int i = 2;i <= cnt / 2;i++) {
			if (cnt % i == 0) {
				flag = 1;
				break;
			}
		}
		if (flag) printf("No");
		else printf("Yes");
	}
	return 0;
}