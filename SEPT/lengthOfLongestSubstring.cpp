//Time:     2022/9/4
//Author:   YonkyG
//Describe: LeetCode

#include<cstdio>
#include<string>
#include<unordered_map>
#include<algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0, len = 0, low = 0; //len: size of window [low, i]
        unordered_map<char, int> ht;
        for (int i = 0;i < s.size();i++) {
            if (ht.count(s[i])) {
                ans = max(ans, len); //update ans
                while (s[low] != s[i]) { //map--
                    ht.erase(s[low]);
                    low++; len--;
                }
                ht[s[low]] = i;
                low++; len--;
            }
            ht[s[i]] = i; //map++
            len++;
        }
        return max(ans, len);
    }
};

int main() {
    Solution ss;
    int ans = ss.lengthOfLongestSubstring("abcabcbb");
    printf("%d", ans);
    return 0;
}