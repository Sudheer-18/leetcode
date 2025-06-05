class Solution {
private:
    bool valid(int i, int j, int n, int m) {
        return i >= 0 && i < n && j >= 0 && j < m;  
    }

public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        queue<pair<int, int>> Q;
        int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int fresh = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 2) {
                    Q.push({i, j});
                    vis[i][j] = true;
                }
                if(grid[i][j] == 1) fresh++;
            }
        }
        int minutes = -1;
        while(!Q.empty()) {
            int sz = Q.size();
            minutes++;
            while(sz--) {
                int r = Q.front().first;
                int c = Q.front().second;
                for(int i = 0; i < 4; i++) {
                    int nr = r + dir[i][0];
                    int nc = c + dir[i][1];
                    if(valid(nr, nc, n, m) && !vis[nr][nc] && grid[nr][nc] == 1) {
                        vis[nr][nc] = true;
                        grid[nr][nc] = 2;
                        fresh--;
                        Q.push({nr, nc});
                    }
                }
                Q.pop();
            }
        }
        if(fresh > 0) return -1;
        return max(0, minutes); 
    }
};
