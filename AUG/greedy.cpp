//Time:     2022/8/23
//Author:   YonkyG
//Describe: ALGORITHM P119

#include<cstdio>
#include<algorithm>
using namespace std;

const int MAXN = 1000;

struct Cake {
	int num;
	int total;
	double price;
	Cake():num(0),total(0),price(0){}
};

bool cmp(const Cake& c1, const Cake& c2) {
	return (c1.price > c2.price);
}

int main() {
	int n, market;
	scanf("%d%d", &n, &market);
	Cake cakes[MAXN];
	for (int i = 0;i < n;i++) {
		scanf("%d", &cakes[i].num);
	}
	for (int i = 0;i < n;i++) {
		scanf("%d", &cakes[i].total);
		cakes[i].price = double(cakes[i].total) / cakes[i].num;
	}
	sort(cakes, cakes + n, cmp);
	double money = 0;
	int p = 0;
	while (market > 0 && p < n) {
		market -= cakes[p].num;
		money += cakes[p].total;
		p++;
	}
	if (market < 0) money += market * cakes[--p].price;
	printf("%.2f\n", money);
	return 0;
}