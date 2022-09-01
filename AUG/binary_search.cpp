//Time:     2022/8/26
//Author:   YonkyG
//Describe: ALGORITHM P130

#include<cstdio>
#include<algorithm>
using namespace std;

const int MAXN = 100;

class Solution {
public:
	int leftSearch(int nums[], int left, int right, int x) { //( , ]
		int mid;
		while (left + 1 < right) {
			mid = left + (right - left) / 2;
			if (nums[mid] >= x) right = mid;
			else left = mid;
		}
		return right;
	}
	int rightSearch(int nums[], int left, int right, int x) { //[ , ]
		int mid;
		while (left < right) {
			mid = left + (right - left) / 2;
			if (nums[mid] >= x) right = mid;
			else left = mid + 1;
		}
		return right - 1;
	}
};

int main() {
	int nums[MAXN] = { 1,3,4,4,6,7,8,8,8,10,11,12,15 }; //[6, 8]
	Solution s;
	int n = 13, x = 8;
	int left = s.leftSearch(nums, -1, n, x);
	int right = s.rightSearch(nums, 0, n, x);
	printf("[%d, %d]\n", left, right);
	return 0;
}