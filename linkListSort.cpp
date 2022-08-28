//Time:     2022/8/28
//Author:   YonkyG
//Describe: ALGORITHM P265

#include<cstdio>
#include<algorithm>

using namespace std;

const int MAXN = 1000;

struct Node {
	int data;
	int addr;
	bool flag;
	int next;
	Node():data(0), addr(-1), flag(0), next(-1) {}
};

bool cmp(const Node& n1, const Node& n2) { //no conflict
	if (!n1.flag || !n2.flag) return n1.flag > n2.flag;
	else return n1.data < n2.data;
}

int main() {
	Node nodes[MAXN];
	int n, head;
	scanf("%d%d", &n, &head);
	int add, dat, nex;
	for (int i = 0;i < n;i++) {
		scanf("%d%d%d", &add, &dat, &nex); //' ' is a character
		nodes[add].data = dat;
		nodes[add].addr = add;
		nodes[add].next = nex;
	}
	printf("--------\n");
	int p = head, cnt = 0;
	while (p != -1) {
		nodes[p].flag = 1;
		p = nodes[p].next;
		cnt++;

	}
	sort(nodes, nodes + MAXN, cmp);
	int i = 0;
	for (;i < cnt - 1;i++) {
		printf("%05d %d %05d\n", nodes[i].addr, nodes[i].data, nodes[i + 1].addr);
	}
	printf("%05d %d -1\n", nodes[i].addr, nodes[i].data);
	return 0;
}