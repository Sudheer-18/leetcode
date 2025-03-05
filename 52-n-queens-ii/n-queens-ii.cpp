class Solution {
public:
    int ans = 0;
     bool Valid(vector<string>& grid,int i ,int j) {
        for(int c = j + 1; c < grid.size(); c++) {
            if(grid[i][c] == 'Q') return false;
        }
        for(int r = i + 1 , c = j + 1; r < grid.size() && c < grid.size(); r++, c++) {
            if(grid[r][c] == 'Q') return false;
        }
        for(int r = i - 1 , c = j + 1; r >= 0 && c < grid.size(); r--, c++) {
            if(grid[r][c] == 'Q') return false;
        }

        return true;
     }
     void helper(int n, vector<string>& grid) {
        if(n < 0) {
           ans++;
            return;
        }
        for(int i = 0; i < grid.size(); i++) {
            if(Valid(grid,i,n)) {
                 char ch = 'Q';
                 swap(grid[i][n] , ch) ;
                 helper(n - 1,grid);
                 swap(grid[i][n] , ch) ;
            }
        }
     }
    int totalNQueens(int n) {
        vector<string> grid(n,string(n,'.'));
        helper(n - 1,grid);
        return ans;
    }
};