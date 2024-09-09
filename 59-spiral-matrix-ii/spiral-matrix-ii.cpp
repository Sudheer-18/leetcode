class Solution {
public:
    void helper(vector<vector<int>>& arr, int n, int mum, int i, int j, int dir) {
        if (i < 0 || j < 0 || i >= n || j >= n || arr[i][j] != -1) return;
        arr[i][j] = mum;
        if (dir == 0) {  
            if (j+1 < n && arr[i][j+1] == -1) helper(arr, n, mum + 1, i, j + 1, 0);  
            else    helper(arr, n, mum + 1, i + 1, j, 1);  
        } 
        else if (dir == 1) { 
            if (i+1 < n && arr[i+1][j] == -1)  helper(arr, n, mum + 1, i + 1, j, 1);  
            else helper(arr, n, mum + 1, i, j - 1, 2);  
        } 
        else if (dir == 2) { 
            if (j-1 >= 0 && arr[i][j-1] == -1) helper(arr, n, mum + 1, i, j - 1, 2);
            else helper(arr, n, mum + 1, i - 1, j, 3); 
        } 
        else if (dir == 3) {  
            if (i-1 >= 0 && arr[i-1][j] == -1) helper(arr, n, mum + 1, i - 1, j, 3);  
            else helper(arr, n, mum + 1, i, j + 1, 0);  
        }
    }

    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> arr(n, vector<int>(n, -1));
        helper(arr, n, 1, 0, 0, 0);
        return arr;
    }
};
