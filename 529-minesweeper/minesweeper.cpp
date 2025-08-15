class Solution {
private:
    int dir[8][2] = {{0,1},{1,0},{-1,0},{0,-1},{1,1},{-1,1},{1,-1},{-1,-1}};
    bool check(int r,int c,int n,int m) {
        return r >= 0 and c >=0 and r < n and c < m;
    }
    void bfs (vector<vector<char>>& V,int r, int c) {
        int n =  V.size();
        int m = V[0].size();
        queue<pair<int,int>> q;
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        q.push({r,c});
        vis[r][c] = false;
        while(!q.empty()) {
            auto [x,y] = q.front();
            q.pop();
            int cnt = 0;
            vector<pair<int,int>> p;
            for(int i=0; i<8; i++) {
                int nx = x + dir[i][0];
                int ny = y + dir[i][1];
                if(check(nx,ny,n,m) && !vis[nx][ny]) {
                    if(V[nx][ny] == 'M')  cnt++;
                    else if(V[nx][ny] == 'E') p.push_back({nx,ny});
                }
            }
            if(cnt == 0) {
                V[x][y] = 'B';
                for(auto it : p) {
                    int i = it.first , s = it.second;
                    if(!vis[i][s]) {
                        q.push({i,s});
                        vis[i][s] = true;
                    }
                }
            }
            else {
                V[x][y] = cnt + '0';
            }
        }

    }
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        if(board[click[0]][click[1]] == 'M') {
            board[click[0]][click[1]] = 'X';
            return board;
        }
        bfs(board,click[0],click[1]);
        return board;
    }
};