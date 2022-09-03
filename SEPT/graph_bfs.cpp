//Time:     2022/9/3
//Author:   YonkyG
//Describe: ALGORITHM P362

#include<cstdio>
#include<queue>
#include<algorithm>

using namespace std;

const int MAXV = 10;
int n;
vector<int> adj[MAXV];
bool inq[MAXV] = { false };

void bfs(int index) {
	queue<int> q;
	q.push(index);
	inq[index] = 1;
	while (!q.empty()) {
		int nd = q.front();
		q.pop();
		for (int i = 0;i < adj[nd].size();i++) {
			int temp = adj[nd][i];
			if (!inq[temp]) {
				q.push(temp);
				inq[temp] = 1;
			}
		}
	}
}

void bfsTrave() {
	for (int i = 0;i < n;i++) {
		if (!inq[i]) bfs(i);
	}
}

int main() {
	

	return 0;
}
