class Solution {
public:
    int n;
    int dir[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
    bool valid(int i, int j) {
        return i >= 0 && j >= 0 && i < n && j < n;
    }
    void dfs(vector<vector<int>>& grid, int i, int j, queue<pair<int,int>>& q, vector<vector<bool>>& vis) {
        if (!valid(i, j) || grid[i][j] != 1 || vis[i][j]) return;
        
        vis[i][j] = true;
        q.push({i, j});
        grid[i][j] = 2; 
        for (int d = 0; d < 4; ++d) {
            int ni = i + dir[d][0];
            int nj = j + dir[d][1];
            dfs(grid, ni, nj, q, vis);
        }
    }
    
    int bfs(vector<vector<int>>& grid, queue<pair<int,int>>& q, vector<vector<bool>>& vis) {
        int level = 0;
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto [x, y] = q.front(); q.pop();
                
                for (int d = 0; d < 4; ++d) {
                    int nx = x + dir[d][0];
                    int ny = y + dir[d][1];
                    
                    if (valid(nx, ny) && !vis[nx][ny]) {
                        if (grid[nx][ny] == 1) {
                            return level; 
                        }
                        if (grid[nx][ny] == 0) {
                            q.push({nx, ny});
                            vis[nx][ny] = true;
                            grid[nx][ny] = 2;
                        }
                    }
                }
            }
            level++;
        }
        return -1;
    }
    
    int shortestBridge(vector<vector<int>>& grid) {
        n = grid.size();
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        queue<pair<int,int>> q;

        bool found = false;
        for (int i = 0; i < n && !found; ++i) {
            for (int j = 0; j < n && !found; ++j) {
                if (grid[i][j] == 1) {
                    dfs(grid, i, j, q, vis);
                    found = true;
                }
            }
        }

        return bfs(grid, q, vis);
    }
};
