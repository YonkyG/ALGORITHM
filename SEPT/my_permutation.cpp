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

void permutation(int index) {
    if (index > n) {
        for (int i = 1;i <= n;i++) {
            printf("%d ", nums[i]);
        }
        printf("\n");
    }
    for (int i = 1;i <= n;i++) {
        if (!vis[i]) {
            vis[i] = 1;
            nums[index] = i;
            permutation(index + 1);
            vis[i] = 0;
        }
    }
}

int main() {
    scanf("%d", &n);
    permutation(1);
    return 0;
}