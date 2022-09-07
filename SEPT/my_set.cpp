//Time:     2022/9/7
//Author:   YonkyG
//Describe: Review

#include<cstdio>
#include<algorithm>

using namespace std;

const int MAXN = 100;
int parent[MAXN];

void merge(int a, int b) {
    int p = a, q = b;
    while (parent[p] != p) p = parent[p];
    while (parent[q] != q) q = parent[q];
    if (p != q) parent[q] = p;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1;i <= n;i++) { //init
        parent[i] = i;
    }
    for (int i = 0;i < m;i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        merge(a, b);
    }
    int cnt = 0;
    for (int i = 1;i <= n;i++) { //init
        if (parent[i] == i) cnt++;
    }
    printf("%d", cnt);
    return 0;
}