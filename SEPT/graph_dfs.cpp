//Time:     2022/9/2
//Author:   YonkyG
//Describe: ALGORITHM P352

#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

const int MAXV = 10;
int n;
vector<int> adj[MAXV];
bool vis[MAXV] = { false };

void dfs(int index) {
	vis[index] = true;
	for (int i = 0;i < adj[index].size();i++) {
		if (!vis[i]) dfs(adj[index][i]);
	}
}

void dfsTrave() {
	for (int i = 0;i < n;i++) {
		if (!vis[i]) dfs(i);
	}
}

int main() {
	

	return 0;
}
