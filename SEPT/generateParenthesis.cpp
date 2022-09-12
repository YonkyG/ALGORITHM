Time     2022912
Author   YonkyG
Describe Leetcode Medium

#includecstdio
#includeiostream
#includevector
#includestring
#includealgorithm

using namespace std;
 
class Solution {
public
    vectorstring v;
    string temp;
    int nn;
    void helper(int left, int right) {
        if (left == nn && right == nn) {
            v.push_back(temp);
            return;
        }
        if (left  nn) {
            temp.push_back('(');
            helper(left + 1, right);
            temp.pop_back();
        }
        if (left  right) {
            temp.push_back(')');
            helper(left, right + 1);
            temp.pop_back();
        }
        return;
    }
    vectorstring generateParenthesis(int n) {
        nn = n;
        helper(0, 0);
        return v;
    }
};

int main() {
    Solution ss;
    vectorstring v;
    v = ss.generateParenthesis(3);
    for (int i = 0;i  v.size();i++) {
        cout  v[i]  endl;
    }
    return 0;
}