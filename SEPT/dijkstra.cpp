//Time:     2022/9/3
//Author:   YonkyG
//Describe: ALGORITHM P371

#include<cstdio>
#include<queue>
#include<algorithm>

using namespace std;

struct Node {
	int index;
	int weight;
};

const int MAXV = 10;
int n;
vector<Node> adj[MAXV];
bool vis[MAXV] = { false };
int shortest[MAXV];

int near() {
	int neighbor = -1, minW = INT_MAX;
	for (int i = 0;i < n;i++) {
		if (!vis[i] && minW > shortest[i]) {
			neighbor = i;
			minW = shortest[i];
		}
	}
	return neighbor;
}

void dijkstra(int s) {
	fill(shortest, shortest + n, INT_MAX);
	shortest[s] = 0;
	for (int i = 0;i < n;i++) {
		s = near();
		if (s == -1) return;
		vis[s] = true;
		for (Node nd : adj[s]) { //update weight
			int v = nd.index;
			if (vis[v]) continue;
			int oldW = shortest[v];
			int newW = shortest[s] + nd.weight;
			if (oldW > newW) shortest[v] = newW;
		}
	}
}

int main() {
	

	return 0;
}
