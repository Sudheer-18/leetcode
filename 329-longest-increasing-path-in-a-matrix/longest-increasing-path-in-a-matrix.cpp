class Solution {
private:
    int dfs(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp, int n, int m) {
        if(dp[i][j] != -1) return dp[i][j];
        int maxLen = 1;
        int dir[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        for(int d = 0; d < 4; d++) {
            int ni = i + dir[d][0];
            int nj = j + dir[d][1];
            if(ni >= 0 && nj >= 0 && ni < n && nj < m && matrix[ni][nj] > matrix[i][j]) {
                maxLen = max(maxLen, 1 + dfs(ni, nj, matrix, dp, n, m));
            }
        }

        return dp[i][j] = maxLen;
    }

public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                ans = max(ans, dfs(i, j, matrix, dp, n, m));
            }
        }

        return ans;
    }
};
