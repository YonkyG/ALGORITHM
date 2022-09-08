//Time:     2022/9/8
//Author:   YonkyG
//Describe: ALGORITHM

#include<cstdio>
#include<algorithm>

using namespace std;

const int MAXN = 100;
int dp[MAXN];

int fib(int n) {
	if (n == 0 || n == 1) return 1;
	if (dp[n] != -1) return dp[n];
	dp[n] = fib(n - 1) + fib(n - 2);
	return dp[n];
}

int main() {

}