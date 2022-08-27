//Time:     2022/8/27
//Author:   YonkyG
//Describe: ALGORITHM P146

#include<cstdio>
#include<algorithm>
#include<ctime>
using namespace std;

const int MAXN = 10;

int quick(int nums[], int left, int right) {
	int p = round(1.0 * rand() / RAND_MAX * (right - left) + left);
	swap(nums[p], nums[left]);
	int i = left, j = right;
	int temp = nums[left];
	while (i < j) {
		while (i < j && nums[j] > temp) j--;
		nums[i] = nums[j];
		while (i < j && nums[i] <= temp) i++;
		nums[j] = nums[i];
	}
	nums[i] = temp;
	return i;
}

void quickSort(int nums[], int left, int right) {
	if (left < right) {
		int mid = quick(nums, left, right);
		quickSort(nums, left, mid - 1);
		quickSort(nums, mid + 1, right);
	}
}

int main() {
	srand((unsigned)time(0));
	int nums[MAXN] = { 66,12,33,57,64,27,18 }, n = 7;
	quickSort(nums, 0, n - 1);
	for (int i = 0;i < n;i++) {
		printf("%d ", nums[i]);
	}
	return 0;
}