class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
       return DFS(grid,0,0,n,m,dp);
    }
    int DFS(vector<vector<int>>& grid,int r ,int c,int n,int m,vector<vector<int>>& dp) {
        if(r >= n ||  c >= m) return INT_MAX;
        if(r == n-1 && c == m-1) return grid[r][c];
        if(dp[r][c] != -1) return dp[r][c];
        int ri = DFS(grid,r,c+1,n,m,dp);
        int le = DFS(grid,r+1,c,n,m,dp);
        return dp[r][c] =  grid[r][c] + min(ri,le);
    }
};