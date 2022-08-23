//Time:     2022/8/23
//Author:   YonkyG
//Describe: ALGORITHM P110

#include<cstdio>

const int MAXN = 100;
char nstr[MAXN][5], temp[5];
int hashtable[26 * 26 * 26 + 10];

int hashFun(char s[], int len) {
	int num = 0;
	for (int i = 0;i < len;i++) {
		num *= 26;
		num += (s[i] - 'A');
	}
	return num;
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0;i < n;i++) {
		scanf("%s", nstr[i]);
		int id = hashFun(nstr[i], 3);
		hashtable[id]++;
	}
	for (int i = 0;i < m;i++) {
		scanf("%s", temp);
		int id = hashFun(temp, 3);
		printf("%d\n", hashtable[id]);
	}
	return 0;
}