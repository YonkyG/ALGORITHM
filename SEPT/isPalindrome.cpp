//Time:     2022/9/9
//Author:   YonkyG
//Describe: Leetcode Easy

#include<cstdio>
#include<stack>
#include<algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
}; 
 
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        int n = 0;
        ListNode* p = head, * q = p;
        stack<int> s;
        while (p && p->next) {
            s.push(q->val);
            q = q->next;
            p = p->next->next;
        }
        if (p) q = q->next; //odd
        while (q) {
            if (q->val != s.top()) return 0;
            s.pop(); q = q->next;
        }
        return 1;
    }
};

int main() {
    
    return 0;
}