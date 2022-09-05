//Time:     2022/9/5
//Author:   YonkyG
//Describe: Review

#include<cstdio>
#include<algorithm>

using namespace std;

const int MAXN = 100;
int n = 8;
int nums[MAXN] = {1,3,3,3,4,6,6,8};
int x;

int start(int low, int high) {
    int mid;
    while (low < high) {
        mid = (low + high) / 2;
        if (nums[mid] >= x) high = mid;
        else low = mid + 1;
    }
    return high;
}

int end(int low, int high) {
    int mid;
    while (low < high) {
        mid = (low + high) / 2;
        if (nums[mid] > x) high = mid;
        else low = mid + 1;
    }
    return high - 1;
}

int main() {
    scanf("%d", &x);
    printf("%d ", start(0, n));
    printf("%d", end(0, n));
    return 0;
}