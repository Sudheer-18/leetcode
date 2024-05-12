
class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> maxLocal(n - 2, vector<int>(n - 2, 0)); // Initialize maxLocal matrix

        // Iterate through the grid to find maximum values in 3x3 submatrices
        for (int i = 1; i < n - 1; ++i) {
            for (int j = 1; j < n - 1; ++j) {
                int maxVal = grid[i - 1][j - 1];
                for (int x = i - 1; x <= i + 1; ++x) {
                    for (int y = j - 1; y <= j + 1; ++y) {
                        maxVal = max(maxVal, grid[x][y]);
                    }
                }
                maxLocal[i - 1][j - 1] = maxVal;
            }
        }

        return maxLocal;
    }
};
