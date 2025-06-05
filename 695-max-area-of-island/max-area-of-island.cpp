class Solution {
private:
    int DFS(vector<vector<int>>& grid, int i, int j, int n, int m, vector<vector<bool>>& vis) {
        if (i < 0 || j < 0 || i >= n || j >= m || vis[i][j] || grid[i][j] != 1)
            return 0;
        vis[i][j] = true;
        int area = 1;
        area += DFS(grid, i + 1, j, n, m, vis);
        area += DFS(grid, i - 1, j, n, m, vis);
        area += DFS(grid, i, j + 1, n, m, vis);
        area += DFS(grid, i, j - 1, n, m, vis);
        return area;
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && !vis[i][j]) {
                    ans = max(ans, DFS(grid, i, j, n, m, vis));
                }
            }
        }

        return ans;
    }
};
