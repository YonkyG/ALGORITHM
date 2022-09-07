//Time:     2022/9/7
//Author:   YonkyG
//Describe: Review

#include<cstdio>
#include<algorithm>

using namespace std;

const int MAXN = 100;
int n = 10;
int heap[MAXN] = { 0,85,55,82,57,68,92,99,98,66,56 }; //static, s.t.(x, 2*x, 2*x+1)

void downAdj(int index, int bound) {
    int p = 2 * index;
    if (p > bound) return;
    if (p + 1 <= bound && heap[p + 1] > heap[p]) p++;
    if (heap[p] > heap[index]) {
        swap(heap[p], heap[index]);
        downAdj(p, bound);
    }
}

void init() {
    for (int i = n / 2;i >= 1;i--) {
        downAdj(i, n);
    }
}

void heapSort() {
    for (int i = n;i >= 1;i--) {
        swap(heap[1], heap[i]);
        downAdj(1, i - 1);
    }
}

void upAdj(int index) {
    int p = index / 2;
    while (p && heap[index] > heap[p]) {
        swap(heap[index], heap[p]);
        p = p / 2;
    }
}

void insert(int x) {
    heap[++n] = x;
    upAdj(n);
}

void delTop() {
    swap(heap[1], heap[n]);
    downAdj(1, --n);
}

int main() {
    init();
    insert(77);
    delTop();
    heapSort();
    for (int i = 1;i <= n;i++) {
        printf("%d ", heap[i]);
    }
    return 0;
}