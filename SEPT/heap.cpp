//Time:     2022/9/1
//Author:   YonkyG
//Describe: ALGORITHM P342

#include<cstdio>
#include<algorithm>

using namespace std;

const int MAXN = 100;
int heap[MAXN] = {0,85,55,82,57,68,92,99,98}, n = 8;

void downAdjust(int low, int high) { //[1, n], high = n
	int root = low;
	int child = 2 * root; //max child
	while (child <= high) { //not leaf
		if (child + 1 <= high && heap[child + 1] > heap[child])
			child++; //right child
		if (heap[child] > heap[root]) { //adjust
			swap(heap[child], heap[root]);
			root = child;
			child = 2 * root;
		}
		else break;
	}
}

void createHeap() {
	for (int i = n / 2;i > 0;i--) {
		downAdjust(i, n);
	}
}

void deleteTop() {
	heap[1] = heap[n--];
	downAdjust(1, n);
}

void upAdjust(int low, int high) { //[1, n], low = 1
	int root = high;
	int parent = root / 2;
	while (parent >= low) {
		if (heap[parent] < heap[root]) {
			swap(heap[parent], heap[root]);
			root = parent;
			parent = root / 2;
		}
		else break;
	}
}

void insertHeap(int data) {
	heap[++n] = data;
	upAdjust(1, n);
}

void heapSort() {
	createHeap();
	for (int i = n;i > 1;i--) {
		swap(heap[1], heap[i]);
		downAdjust(1, i - 1);
	}
}

int main() {
	createHeap();
	deleteTop();
	insertHeap(100);
	heapSort();
	for (int i = 1;i <= n;i++) {
		printf("%d ", heap[i]);
	}
	return 0;
}

/*void downAdjust(int x) { //recursive
	if (!heap[x]) return;
	bool left = 0; //change left
	int m = 0; //max child
	if (heap[2 * x] > heap[2 * x + 1]) {
		left = 1; m = heap[2 * x];
	}
	else m = heap[2 * x + 1];
	if (m > heap[x]) { //adjust
		if (left) {
			swap(heap[x], heap[2 * x]);
			downAdjust(2 * x);
		}
		else {
			swap(heap[x], heap[2 * x + 1]);
			downAdjust(2 * x + 1);
		}
	}
}*/