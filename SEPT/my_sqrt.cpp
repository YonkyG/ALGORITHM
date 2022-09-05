//Time:     2022/9/5
//Author:   YonkyG
//Describe: Review

#include<cstdio>
#include<algorithm>

using namespace std;

const double eps = 1e-5;
int n;

double solve(double low, double high) {
    double mid = (low + high) / 2;
    while (abs(mid * mid - n) > eps) {
        if (mid * mid > n) high = mid;
        else low = mid;
        mid = (low + high) / 2;
    }
    return mid;
}

int main() {
    scanf("%d", &n);
    printf("%.2f", solve(1, n));
    return 0;
}