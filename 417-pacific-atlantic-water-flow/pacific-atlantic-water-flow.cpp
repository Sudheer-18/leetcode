class Solution {
private:
    bool check(int r,int c,int n,int m) {
        return r >= 0 && c >= 0 && r < n && c < m;
    }
    void bfs(vector<vector<int>>& heights,vector<vector<bool>>& vis,queue<pair<int,int>> pq) {
        int r = heights.size();
        int c = heights[0].size();
        int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
        while(!pq.empty()) {
            int x = pq.front().first;
            int y = pq.front().second;
            pq.pop();
            for(int i=0; i<4; i++) {
                int nx = dir[i][0] + x;
                int ny = dir[i][1] + y;
                if(check(nx,ny,r,c)) {
                    if(heights[nx][ny] >= heights[x][y] && ! vis[nx][ny]) {
                        vis[nx][ny] = true;
                        pq.push({nx,ny});
                    }
                }
            }
        }
         
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> ans;
        int r = heights.size();
        int c = heights[0].size();
        vector<vector<bool>> pOcean(r,vector<bool>(c,false));
        vector<vector<bool>>aOcean(r,vector<bool>(c,false));
        queue<pair<int,int>> q1, q2;
        for(int i=0; i<r; i++) {
            q1.push({i,0});
            q2.push({i,c-1});
            pOcean[i][0] = true;
            aOcean[i][c-1] = true;
        }
        for(int i=0; i<c; i++) {
            q1.push({0,i});
            q2.push({r-1,i});
            pOcean[0][i] = true;
            aOcean[r-1][i] = true;
        }
        bfs(heights,pOcean,q1);
        bfs(heights,aOcean,q2);
        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++) {
                if(pOcean[i][j] && aOcean[i][j]) ans.push_back({i,j});
            }
        }
       return ans;
    }
};