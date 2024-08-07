class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    map<char, int> mp;
    int i = 0, max_len = 0;
    int n = s.length();
    for (int j = 0; j < n; j++) {
        if (mp.find(s[j]) != mp.end()) {
            i = max(i, mp[s[j]] + 1);
        }
        mp[s[j]] = j;
        max_len = max(max_len, j - i + 1);
    }
    return max_len;
    }
};