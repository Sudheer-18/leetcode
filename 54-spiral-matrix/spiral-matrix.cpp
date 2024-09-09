class Solution {
public:
    void recursion(vector<vector<int>>& arr, vector<int>& ans, int m, int n, int i, int j, int dir, vector<vector<bool>>& visited) {
        if(i < 0 || j < 0 || i >= m || j >= n || visited[i][j]) return;
        visited[i][j] = true;
        ans.push_back(arr[i][j]);
        if (dir == 0) { 
            if (j + 1 < n && !visited[i][j + 1]) 
                recursion(arr, ans, m, n, i, j + 1, 0, visited);
            else 
                recursion(arr, ans, m, n, i + 1, j, 1, visited);  
        } 
        else if (dir == 1) {  
            if (i + 1 < m && !visited[i + 1][j]) 
                recursion(arr, ans, m, n, i + 1, j, 1, visited);
            else 
                recursion(arr, ans, m, n, i, j - 1, 2, visited);  
        } 
        else if (dir == 2) { 
            if (j - 1 >= 0 && !visited[i][j - 1]) 
                recursion(arr, ans, m, n, i, j - 1, 2, visited);
            else 
                recursion(arr, ans, m, n, i - 1, j, 3, visited); 
        } 
        else if (dir == 3) { 
            if (i - 1 >= 0 && !visited[i - 1][j]) 
                recursion(arr, ans, m, n, i - 1, j, 3, visited);
            else 
                recursion(arr, ans, m, n, i, j + 1, 0, visited);  
        }
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();         
        int n = matrix[0].size();      
        vector<int> res;              
        vector<vector<bool>> visited(m, vector<bool>(n, false)); 
        recursion(matrix, res, m, n, 0, 0, 0, visited);
        return res;
    }
};
