class Solution {
public:
    bool island = false;
    void dfs(vector<vector<int>>& arr1,vector<vector<int>>& arr2,int i,int j,int n,int m) {
        if(arr1[i][j] != arr2[i][j]) island = false;
        arr2[i][j] = 0;
        arr1[i][j] = 0;
        int a[] = {0,0,1,-1};
        int b[] = {1,-1,0,0};
        for(int ind = 0;ind<4;ind++) {
            int x = i+a[ind];
            int y = j+b[ind];
            if(x>=0 && x<n &&  y>=0 && y<m && arr2[x][y] ==1) dfs(arr1,arr2,x,y,n,m);
        }
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int cnt = 0;
        int n = grid2.size();
        int m = grid2[0].size();
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid2[i][j] == 1) {
                    island= true;
                    dfs(grid1,grid2,i,j,n,m);
                    if(island) cnt+=1;
                }
            }
        }
          return cnt;
    }
};