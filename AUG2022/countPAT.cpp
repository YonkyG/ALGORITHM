//Time:     2022/8/27
//Author:   YonkyG
//Describe: ALGORITHM P147

#include<cstdio>
#include<algorithm>
using namespace std;

const int MAXN = 100;
const int MOD = 100007;

int main() {
	char str[] = "PAPPAPTT"; //PAT
	int pNum[MAXN] = { 0 }, n = 8, ans = 0;
	int temp = 0; //count P
	for (int i = 0;i < n;i++) {
		if (str[i] == 'P') temp++;
		if (str[i] == 'A') pNum[i] = temp;
	}
	temp = 0; //count T
	for (int i = n - 1;i >= 0;i--) {
		if (str[i] == 'T') temp++;
		if (str[i] == 'A') ans = (ans + pNum[i] * temp) % MOD;
	}
	printf("%d\n", ans);
	return 0;
}