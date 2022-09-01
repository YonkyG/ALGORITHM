//Time:     2022/8/27
//Author:   YonkyG
//Describe: ALGORITHM P149

#include<cstdio>
#include<algorithm>
#include<ctime>
using namespace std;

const int MAXN = 10;

int partition(int nums[], int left, int right) {
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

int randSelect(int nums[], int left, int right, int k) {
	int p = partition(nums, left, right);
	if (p == k) return nums[p];
	if (p > k) return randSelect(nums, left, p - 1, k);
	else return randSelect(nums, p + 1, right, k);
}

int main() {
	srand((unsigned)time(0));
	int nums[MAXN] = { 66,12,33,57,64,27,18 }, n = 7;
	int k = 6;
	int ans = randSelect(nums, 0, n - 1, k - 1);
	printf("ans = %d\n", ans);
	return 0;
}