class Solution {
private:
    bool isvalid(int i, int j, int n, int m) {
        return i >= 0 && j >= 0 && i < n && j < m;
    }
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        queue<pair<int, int>> Q;
        vector<vector<bool>>Vis(n,vector<bool>(m,false));
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
                    if (board[i][j] == 'O' && !Vis[i][j]) {
                        Q.push({i, j});
                        Vis[i][j] = true;
                    }
                }
            }
        }
        int dir[4][2] = {{0, 1}, {-1, 0}, {1, 0}, {0, -1}};
        while (!Q.empty()) {
            int x = Q.front().first;
            int y = Q.front().second;
            Q.pop();
            for (int i = 0; i < 4; i++) {
                int dx = x + dir[i][0];
                int dy = y + dir[i][1];
                // cout<<"DX "<<dx<<" DY "<<dy<<endl;
                if (isvalid(dx, dy, n, m) && board[dx][dy] == 'O' && !Vis[dx][dy]) {
                    Q.push({dx,dy});
                    Vis[dx][dy] = true;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O' && !Vis[i][j]) { 
                    board[i][j] = 'X';
                }
            }
        }
    }
};
