//Time:     2022/9/10
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
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = 0, * np = head;
        while (np) {
            ListNode* post = np->next;
            np->next = pre;
            pre = np;
            np = post;
        }
        return pre;
    }
    bool isPalindrome_plus(ListNode* head) {
        ListNode* p = head, * q = p;
        while (p && p->next) {
            q = q->next;
            p = p->next->next;
        }
        p = head;
        ListNode* rear = reverseList(q), * r = rear;
        while (r) {
            if (p->val != r->val) return 0;
            p = p->next;
            r = r->next;
        }
        reverseList(rear);
        return 1;
    }
};

int main() {
    ListNode* rear = new ListNode(2);
    ListNode* head = new ListNode(1, rear);
    Solution ss;
    printf("%d", ss.isPalindrome_plus(head));
    return 0;
}