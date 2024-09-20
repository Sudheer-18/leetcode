class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.length();
        if (n == 0) return s;
        int prefix = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (is_palindrome(s, 0, i)) {
                prefix = i + 1;
                break;
            }
        }
        string suffix = s.substr(prefix);
        reverse(suffix.begin(), suffix.end());
        return suffix + s;
    } 
    bool is_palindrome(string& s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end]) return false;
            start++;
            end--;
        }
        return true;
    }
};
