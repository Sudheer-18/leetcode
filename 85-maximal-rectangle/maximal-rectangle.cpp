#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int maxArea = 0;
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> heights(cols, 0); // Store heights of consecutive '1's
        for (int i = 0; i < rows; ++i) {
            // Update heights based on current row
            for (int j = 0; j < cols; ++j) {
                if (matrix[i][j] == '1')
                    heights[j]++;
                else
                    heights[j] = 0;
            }
            // Calculate maximum area using current heights
            int area = 0;
            for (int j = 0; j < cols; ++j) {
                int minHeight = heights[j];
                // Calculate area using current column as the right boundary
                for (int k = j; k >= 0; --k) {
                    minHeight = min(minHeight, heights[k]);
                    area = max(area, minHeight * (j - k + 1));
                }
            }
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }
};
