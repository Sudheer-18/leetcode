class Solution {
public:
    vector<int> ans;
    void spiral_matrix(vector<vector<int>>& arr,int i,int j,int n, int m ,int dir) {
        if (i < 0 || i >= n || j < 0 || j >= m || arr[i][j] == -1000) return;
        ans.push_back(arr[i][j]);
        arr[i][j] = -1000;
        if (dir == 0) { 
            if (j + 1 < m && arr[i][j + 1] != -1000)
                spiral_matrix(arr, i, j + 1, n, m, 0);
            else
                spiral_matrix(arr, i + 1, j, n, m, 1);
        } 
        else if (dir == 1) { 
            if (i + 1 < n && arr[i + 1][j] != -1000)
                spiral_matrix(arr, i + 1, j, n, m, 1);
            else
                spiral_matrix(arr, i, j - 1, n, m, 2);
        } 
        else if (dir == 2) {
            if (j - 1 >= 0 && arr[i][j - 1] != -1000)
                spiral_matrix(arr, i, j - 1, n, m, 2);
            else
                spiral_matrix(arr, i - 1, j, n, m, 3);
        } 
        else if (dir == 3) { 
            if (i - 1 >= 0 && arr[i - 1][j] != -1000)
                spiral_matrix(arr, i - 1, j, n, m, 3);
            else
                spiral_matrix(arr, i, j + 1, n, m, 0);
        }

    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        spiral_matrix(matrix,0,0,matrix.size(),matrix[0].size(), 0);
        return ans;
    }
};