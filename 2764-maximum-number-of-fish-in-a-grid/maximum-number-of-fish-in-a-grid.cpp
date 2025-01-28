class Solution {
public:
    int helper(vector<vector<int>>& arr, vector<vector<bool>>& vis, int n, int m, int i, int j) {
        if (i < 0 || j < 0 || i >= n || j >= m || vis[i][j] || arr[i][j] == 0) 
            return 0;
        vis[i][j] = true;
        int cf = arr[i][j]; 
        vector<vector<int>> dir {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (int k = 0; k < 4; k++) {
            cf += helper(arr, vis, n, m, i + dir[k][0], j + dir[k][1]);
        }
        return cf;
    }

    int findMaxFish(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int maxFish = 0;
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] > 0) {
                    int cf = helper(grid, vis, n, m, i, j);
                    maxFish = max(maxFish, cf);
                }
            }
        }

        return maxFish;
    }
};
