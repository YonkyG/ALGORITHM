//Time:     2022/8/29
//Author:   YonkyG
//Describe: ALGORITHM P277

#include<cstdio>
#include<algorithm>

using namespace std;

int matrix[4][4];
bool inq[4][4]; //visited
int incx[] = { 0,0,1,-1 };
int incy[] = { 1,-1,0,0 };

struct Node {
	int x, y;
	Node(int i, int j):x(i),y(j){}
};

bool check(int nx, int ny) {
	if (nx >= 0 && nx < 4 && ny >= 0 && ny < 4) { //in matrix
		if (matrix[nx][ny] && !inq[nx][ny]) {
			inq[nx][ny] = 1; return 1;
		}
		return 0;
	}
	return 0;
}

void dfs(int x, int y) {
	if (!check(x, y)) return;
	int nx, ny;
	for (int k = 0;k < 4;k++) {
		nx = x + incx[k];
		ny = y + incy[k];
		dfs(nx, ny);
	}
}

int main() {
	int one[16] = { 0,1,1,0,0,0,1,0,1,0,0,0,1,0,1,0 };
	for (int i = 0;i < 4;i++) {
		for (int j = 0;j < 4;j++) {
			matrix[i][j] = one[4 * i + j];
			inq[i][j] = 0;
		}
	}
	int cnt = 0;
	for (int i = 0;i < 4;i++) {
		for (int j = 0;j < 4;j++) {
			if (matrix[i][j] && !inq[i][j]) {
				dfs(i, j);
				cnt++;
			}
		}
	}
	printf("Block num = %d\n", cnt);
	return 0;
}