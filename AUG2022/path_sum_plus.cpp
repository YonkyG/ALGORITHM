//Time:     2022/8/30
//Author:   YonkyG
//Describe: ALGORITHM P307

#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

struct Node {
	int w;
	vector<int> child;
	Node():w(0){}
};

const int MAXN = 100;
int s; //path sum
Node tree[MAXN];
vector<int> path;

void dfs(int index, int sum) {
	if (sum > s) return;
	Node& nNode = tree[index];
	if (sum == s) {
		if (nNode.child.empty()) { //save
			for (int num : path) printf("%d ", num);
			printf("\n");
		}
		return;
	}
	for (int i = 0;i < nNode.child.size();i++) {
		int cld = nNode.child[i];
		path.push_back(tree[cld].w);
		dfs(cld, sum + tree[cld].w);
		path.pop_back();
	}
}

bool cmp(int a, int b) {
	return tree[a].w > tree[b].w;
}

int main() {
	int n, m;
	scanf("%d%d%d", &n, &m, &s);
	for (int i = 0;i < n;i++) {
		scanf("%d", &tree[i].w);
	}
	for (int i = 0;i < m;i++) {
		int index = 0, cnum = 0, cld = 0;
		scanf("%d%d", &index, &cnum);
		vector<int>& clds = tree[index].child;
		for (int j = 0;j < cnum;j++) {
			scanf("%d", &cld);
			clds.push_back(cld);
		}
		sort(clds.begin(), clds.end(), cmp);
	}
	path.push_back(tree[0].w);
	dfs(0, tree[0].w);
	return 0;
}