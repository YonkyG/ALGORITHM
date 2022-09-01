//Time:     2022/8/29
//Author:   YonkyG
//Describe: ALGORITHM P279

#include<cstdio>
#include<queue>
#include<algorithm>

using namespace std;

char matrix[5][5];
int inq[5][5]; //queue enrolled

int incx[] = { 0,0,1,-1 };
int incy[] = { 1,-1,0,0 };

struct Node {
	int x, y, step;
	Node(int i, int j, int s) :x(i), y(j), step(s) {}
};

int bfs(int sx, int sy, int tx, int ty) {
	queue<Node> q;
	q.push(Node(sx, sy, 0));
	while (!q.empty()) {
		Node n = q.front();
		q.pop();
		if (n.x == tx && n.y == ty) return n.step;
		int nx, ny;
		for (int k = 0;k < 4;k++) {
			nx = n.x + incx[k];
			ny = n.y + incy[k];
			if (nx >= 0 && nx < 5 && ny >= 0 && ny < 5) { //in matrix
				if (matrix[nx][ny] == '.' && !inq[nx][ny]) {
					q.push(Node(nx, ny, n.step + 1));
					inq[nx][ny] = 1;
				}
			}
		}
	}
	return -1;
}

int main() {
	char str[] = "......*.*..*.*..***.....*";
	for (int i = 0;i < 5;i++) {
		for (int j = 0;j < 5;j++) {
			matrix[i][j] = str[5 * i + j];
			inq[i][j] = 0;
		}
	}
	printf("Min step = %d\n", bfs(2, 2, 4, 3));
	return 0;
}