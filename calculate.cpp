//Time:     2022/8/28
//Author:   YonkyG
//Describe: ALGORITHM P247

#include<cstdio>
#include<algorithm>
#include<string>
#include<stack>
#include<queue>
#include<map>
using namespace std;

const int MAXN = 10;

struct Node {
	int num;
	char op;
	bool flag; //=0 num, =1 op
	Node(int n, char p, bool f) :num(n), op(p), flag(f) {}
};

void change(string& str, queue<Node>& post, map<char, int>& m) {
	stack<Node> opStack;
	string::iterator it = str.begin();
	while (it != str.end()) {
		if (*it >= '0' && *it <= '9') { //num
			int num = 0;
			while (it != str.end() && *it >= '0' && *it <= '9') {
				num = num * 10 + *it - '0';
				it++;
			}
			post.push(Node(num, 0, 0));
		}
		else { //op
			if (*it == '(') opStack.push(Node(0, *it, 1));
			else if (*it == ')') {
				while (opStack.top().op != '(') {
					post.push(opStack.top());
					opStack.pop();
				}
				opStack.pop(); //'('
			}
			else {
				while (!opStack.empty() && m[*it] <= m[opStack.top().op]) {
					post.push(opStack.top());
					opStack.pop();
				}
				opStack.push(Node(0, *it, 1));
			}
			it++;
		}
	}
	while (!opStack.empty()) {
		post.push(opStack.top());
		opStack.pop();
	}
}

double cal(queue<Node>& post) {
	stack<double> temp;
	while (!post.empty()) {
		if (!post.front().flag) { //num
			temp.push(post.front().num);
			post.pop();
		}
		else { //op
			double m = temp.top(); temp.pop();
			double n = temp.top(); temp.pop();
			double a = 0;
			switch (post.front().op) {
			case '+': a = n + m; break;
			case '-': a = n - m; break;
			case '*': a = n * m; break;
			case '/': a = m ? n / m : INT_MAX; break; //?
			default: break;
			}
			temp.push(a);
			post.pop();
		}
	}
	return temp.top();
}

int main() {
	//string str = "5 + 2 * 3 / 49 - 4 / 13";
	string str = "4 * (2 + 3 / 6)   / 2";
	for (string::iterator it = str.begin();it != str.end();it++) {
		if (*it == ' ') str.erase(it--);
	}
	queue<Node> post;
	map<char, int> m;
	m['+'] = 0; m['-'] = 0;
	m['*'] = 1; m['/'] = 1;
	m['('] = -1; //Or line 44 && op != '('
	change(str, post, m);
	printf("ans = %.2f\n", cal(post));
	return 0;
}