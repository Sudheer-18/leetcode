class Solution {
private:
    bool isvalid(int i,int j,int n,int m) {
        return i >= 0 && j >= 0 &&  i < n && j < m; 
    }
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();
        queue<pair<int,int>>Q;
        for(int i=0; i<row; i++) {
            for(int j=0; j<col; j++) {
                if(mat[i][j] == 0) {
                    Q.push({i,j});
                }
                else {
                    mat[i][j] = INT_MAX;
                }
            }
        }
        // vector<vector<bool> vis(n,vector<bool>(m,false));
        int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
        while(!Q.empty()) {
            int dr = Q.front().first;
            int dc = Q.front().second;
            Q.pop();
            for(int i=0; i<4; i++) {
                int x = dr + dir[i][0];
                int y = dc + dir[i][1];
                if(isvalid(x,y,row,col) && mat[x][y] > mat[dr][dc]+1) {
                    Q.push({x,y});
                    mat[x][y] = mat[dr][dc] + 1;

                } 
            }
        }

        return mat;
    }
};