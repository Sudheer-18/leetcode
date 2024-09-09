class Solution {
public:
    void dfs(vector<vector<int>>& arr, ListNode* head, int m, int n, int i, int j, int dir) {
        if (i >= m || i < 0 || j >= n || j < 0 || head == nullptr || arr[i][j] != -1) return;     
        arr[i][j] = head->val;
        if (dir == 0) { 
            if (j + 1 < n && arr[i][j + 1] == -1) {
                dfs(arr, head->next, m, n, i, j + 1, 0);  
            } 
            else {
                dfs(arr, head->next, m, n, i + 1, j, 1); 
            }
        } 
        else if (dir == 1) {  
            if (i + 1 < m && arr[i + 1][j] == -1) {
                dfs(arr, head->next, m, n, i + 1, j, 1);  
            } 
            else {
                dfs(arr, head->next, m, n, i, j - 1, 2);  
            }
        } 
        else if (dir == 2) { 
            if (j - 1 >= 0 && arr[i][j - 1] == -1) {
                dfs(arr, head->next, m, n, i, j - 1, 2);  
            } 
            else {
                dfs(arr, head->next, m, n, i - 1, j, 3);  
            }
        } 
        else if (dir == 3) {  
            if (i - 1 >= 0 && arr[i - 1][j] == -1) {
                dfs(arr, head->next, m, n, i - 1, j, 3);  
            } 
            else {
                dfs(arr, head->next, m, n, i, j + 1, 0);  
            }
        }
    }

    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> arr(m, vector<int>(n, -1));
        dfs(arr, head, m, n, 0, 0, 0);
        return arr;
    }
};
