class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i, int j) {
        int n = grid.size();
        if(i < 0 || j < 0 || i >= n || j >= n || grid[i][j] != 0) return;
        grid[i][j] = 1;
        dfs(grid, i - 1, j); 
        dfs(grid, i + 1, j); 
        dfs(grid, i, j - 1); 
        dfs(grid, i, j + 1); 
    }

    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        int size = n * 3;
        vector<vector<int>> arr(size, vector<int>(size, 0));
        for (int i = 0; i < n;i++) {
            for (int j = 0; j < n;j++) {
                if (grid[i][j] == '/') {
                    arr[i * 3][j * 3 + 2] = 1;
                    arr[i * 3 + 1][j * 3 + 1] = 1;
                    arr[i * 3 + 2][j * 3] = 1;
                }
                else if (grid[i][j] == '\\') {
                    arr[i * 3][j * 3] = 1;
                    arr[i * 3 + 1][j * 3 + 1] = 1;
                    arr[i * 3 + 2][j * 3 + 2] = 1;
                }
            }
        }
        int regions = 0;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (arr[i][j] == 0) { 
                    dfs(arr, i, j);
                    ++regions;
                }
            }
        }

        return regions;
    }
};
