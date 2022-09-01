//Time:     2022/8/28
//Author:   YonkyG
//Describe: ALGORITHM P262

#include<cstdio>
#include<algorithm>

using namespace std;

const int MAXN = 100;

struct Node {
	char data;
	bool flag;
	int next;
	Node():data(0), flag(0), next(-1) {}
};

int main() {
	Node nodes[MAXN];
	int ha, hb, n;
	scanf("%d%d%d", &ha, &hb, &n);
	int add, nex;
	char dat;
	for (int i = 0;i < n;i++) {
		scanf("%d %c %d", &add, &dat, &nex); //' ' is a character
		nodes[add].data = dat;
		nodes[add].next = nex;
	}
	int index = ha;
	while (index != -1) {
		nodes[index].flag = 1;
		index = nodes[index].next;
	}
	index = hb;
	while (index != -1 && !nodes[index].flag) {
		index = nodes[index].next;
	}
	printf("%d\n", index);
	return 0;
}