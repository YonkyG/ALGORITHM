//Time:     2022/8/30
//Author:   YonkyG
//Describe: ALGORITHM P307

#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

struct Node {
	int w, sum, parent;
	vector<int> child;
	Node():w(0), sum(0), parent(-1) {}
};

const int MAXN = 100;
int s; //path sum
Node tree[MAXN];
vector<vector<int>> ans;

void dfs(int index) {
	//printf("Index is %d, sum = %d\n", index, tree[index].sum);
	if (tree[index].child.empty() && tree[index].sum == s) {
		vector<int> temp;
		int p = index;
		while (tree[p].parent != -1) {
			temp.push_back(tree[p].w);
			p = tree[p].parent;
		}
		temp.push_back(tree[0].w);
		reverse(temp.begin(), temp.end());
		ans.push_back(temp);
		return;
	}
	if (tree[index].sum >= s) return;
	for (int j = 0;j < tree[index].child.size();j++) {
		int cld = tree[index].child[j];
		tree[cld].sum = tree[index].sum + tree[cld].w;
		tree[cld].parent = index;
		dfs(cld);
	}
}

bool cmp(const vector<int>& pa, const vector<int>& pb) {
	int len = min(pa.size(), pb.size());
	int i = 0;
	while (i < len && pa[i] == pb[i]) i++;
	if (i == len) return pa.size() > pb.size(); //attention!
	else return pa[i] > pb[i];
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
		for (int j = 0;j < cnum;j++) {
			scanf("%d", &cld);
			tree[index].child.push_back(cld);
		}
	}
	tree[0].sum = tree[0].w;
	dfs(0);
	sort(ans.begin(), ans.end(), cmp);
	for (vector<int> path : ans) {
		for (int i : path) {
			printf("%d ", i);
		}
		printf("\n");
	}
	return 0;
}

/*20 9 24
10 2 4 3 5 10 2 18 9 7 2 2 1 3 12 1 8 6 2 2
00 4 01 02 03 04
02 1 05
04 2 06 07
03 3 11 12 13
06 1 09
07 2 08 10
16 1 15
13 3 14 16 17
17 2 18 19*/