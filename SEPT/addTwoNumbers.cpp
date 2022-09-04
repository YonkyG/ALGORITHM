//Time:     2022/9/4
//Author:   YonkyG
//Describe: LeetCode

#include<cstdio>
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p = l1, * q = l2;
        ListNode* dummy = new ListNode();
        ListNode* r = dummy;
        int carry = 0;
        while (p || q || carry) {
            int temp = carry;
            if (p) {
                temp += p->val;
                p = p->next;
            }
            if (q) {
                temp += q->val;
                q = q->next;
            }
            carry = (temp >= 10);
            r->next = new ListNode(temp % 10);
            r = r->next;
        }
        return dummy->next;
    }
};