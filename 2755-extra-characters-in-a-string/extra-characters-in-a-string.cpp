class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.length();
        unordered_set<string> dict(dictionary.begin(), dictionary.end());
        vector<int> dp(n + 1, n); 
        dp[0] = 0;
        for (int i = 1; i <= n; ++i) {
            dp[i] = dp[i - 1] + 1; 
            for (int j = i - 1; j >= 0; --j) {
                string sub = s.substr(j, i - j);
                if (dict.find(sub) != dict.end()) {
                    dp[i] = min(dp[i], dp[j]);
                }
            }
        }
        
        return dp[n];
    }
};
