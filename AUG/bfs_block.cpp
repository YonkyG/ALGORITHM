//Time:     2022/8/29
//Author:   YonkyG
//Describe: ALGORITHM P277

#include<cstdio>
#include<queue>
#include<algorithm>

using namespace std;

int matrix[4][4];
bool inq[4][4]; //queue enrolled
int incx[] = { 0,0,1,-1 };
int incy[] = { 1,-1,0,0 };

struct Node {
	int x, y;
	Node(int i, int j):x(i),y(j){}
};

void bfs(int i, int j) {
	queue<Node> q;
	q.push(Node(i, j));
	while (!q.empty()) {
		Node n = q.front();
		q.pop();
		int nx, ny;
		for (int k = 0;k < 4;k++) {
			nx = n.x + incx[k];
			ny = n.y + incy[k];
			if (nx >= 0 && nx < 4 && ny >= 0 && ny < 4) { //in matrix
				if (matrix[nx][ny] && !inq[nx][ny]) {
					q.push(Node(nx, ny));
					inq[nx][ny] = 1;
				}
			}
		}
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
				bfs(i, j);
				cnt++;
			}
		}
	}
	printf("Block num = %d\n", cnt);
	return 0;
}