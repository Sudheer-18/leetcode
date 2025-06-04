class Solution {
public:
    void helper(vector<vector<char>>& grid, int n, int m, vector<vector<bool>>& vis, int i, int j) {
        if(i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == '0' || vis[i][j]) return;
        vis[i][j] = true;
        helper(grid, n, m, vis, i+1, j);
        helper(grid, n, m, vis, i-1, j);
        helper(grid, n, m, vis, i, j+1);
        helper(grid, n, m, vis, i, j-1);
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == '1' && !vis[i][j]) {
                    ans++;
                    helper(grid, n, m, vis, i, j);
                }
            }
        }
        return ans;
    }
};
