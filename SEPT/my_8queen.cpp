//Time:     2022/9/5
//Author:   YonkyG
//Describe: Review

#include<cstdio>
#include<algorithm>

using namespace std;

const int MAXN = 100;
bool vis[MAXN];
int nums[MAXN];
int n;
int cnt = 0;

void permutation(int index) {
    if (index > n) {
        cnt++; return;
    }
    for (int i = 1;i <= n;i++) { //(index, i) (j, nums[j])
        if (!vis[i]) {
            bool flag = 0;
            for (int j = 1;j < index;j++) {
                if (abs(index - j) == abs(i - nums[j])) {
                    flag = 1; break;
                }
            }
            if (!flag) {
                vis[i] = 1;
                nums[index] = i;
                permutation(index + 1);
                vis[i] = 0;
            }
        }
    }
}

int main() {
    scanf("%d", &n);
    permutation(1);
    printf("%d", cnt);
    return 0;
}