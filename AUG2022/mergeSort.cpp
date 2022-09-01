//Time:     2022/8/27
//Author:   YonkyG
//Describe: ALGORITHM P139

#include<cstdio>
#include<algorithm>
using namespace std;

const int MAXN = 10;

void merge(int nums[], int left_1, int right_1, int left_2, int right_2) {
	int i = left_1, j = left_2;
	int temp[MAXN] = {0}, index = 0;
	while (i <= right_1 && j <= right_2) {
		if (nums[i] < nums[j]) temp[index++] = nums[i++];
		else temp[index++] = nums[j++];
	}
	while (i <= right_1) temp[index++] = nums[i++];
	while (j <= right_2) temp[index++] = nums[j++];
	for (int k = 0;k < index;k++) {
		nums[left_1 + k] = temp[k];
	}
}

void mergeSort(int nums[], int left, int right) {
	if (left < right) {
		int mid = left + (right - left) / 2;
		mergeSort(nums, left, mid);
		mergeSort(nums, mid + 1, right);
		merge(nums, left, mid, mid + 1, right);
	}
}

void mergeSort(int nums[], int n) {
	for (int step = 2;step / 2 < n;step *= 2) {
		for (int i = 0;i < n;i += step) {
			int mid = i + step / 2 - 1;
			if (mid + 1 < n) { //last
				merge(nums, i, mid, mid + 1, min(n - 1, i + step - 1));
			}
		}
	}
}

int main() {
	int nums[MAXN] = { 66,12,33,57,64,27,18 }, n = 7;
	//mergeSort(nums, 0, n - 1);
	mergeSort(nums, n);
	for (int i = 0;i < n;i++) {
		printf("%d ", nums[i]);
	}
	return 0;
}