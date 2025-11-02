class Solution {
public:
    bool valid(int x, int y, int n ,int m) {
        return x >= 0 && y >= 0 && x < n && y < m ;
    }

    int countUnguarded(int n, int m, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> dir = {{0,1},{1,0},{0,-1},{-1,0}}; 
        vector<vector<int>> v(n, vector<int>(m, 0)); 
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for (auto x : guards) v[x[0]][x[1]] = 1;
        for (auto x : walls)  v[x[0]][x[1]] = 2;
        queue<pair<int,int>> q;
        for (auto g : guards) q.push({g[0], g[1]});
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nx = x + dir[i][0];
                int ny = y + dir[i][1];
                while (valid(nx, ny, n, m) && v[nx][ny] != 2 && v[nx][ny] != 1) {
                    if (v[nx][ny] == 0) v[nx][ny] = 3;
                    nx += dir[i][0];
                    ny += dir[i][1];
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (v[i][j] == 0) ans++;
            }
        }

        return ans;
    }
};
