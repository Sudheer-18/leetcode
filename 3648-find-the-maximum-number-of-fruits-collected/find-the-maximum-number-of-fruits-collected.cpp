class Solution {
public:
    bool check(int i,int j,int N) {
        return i >= 0 && j >= 0 && i < N && j < N;
    }
    int dfs(int i,int j,vector<vector<int>>& dp,vector<vector<int>>& fruits,int N, vector<vector<int>>& dir,bool up) {
        if(!check(i,j,N)) return 0;
        if(up) { 
            if(i == j || i > j) return 0;
        } 
        else {   
            if(i == j || j > i) return 0;
        }
        if(i == N-1 && j == N-1) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int score = fruits[i][j];
        int best = 0;
        for(int k=0; k<3; k++) {
            int x = i + dir[k][0];
            int y = j + dir[k][1];
            best = max(best, score + dfs(x,y,dp,fruits,N,dir,up));
        }
        return dp[i][j] = best;
    }

    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int N = fruits.size();
        int ps1 = 0;
        for(int i=0; i<N; i++) {
            ps1 += fruits[i][i];
            fruits[i][i] = 0;
        }
        vector<vector<int>> dirp2 = {{1,-1},{1,0},{1,1}};
        vector<vector<int>> dirp3 = {{-1,1},{0,1},{1,1}};
        vector<vector<int>> dp1(N,vector<int>(N,-1));
        // vector<vector<int>> dp2(N,vector<int>(N,-1));
        int ps2 = dfs(0,N-1,dp1,fruits,N,dirp2,true);
        int ps3 = dfs(N-1,0,dp1,fruits,N,dirp3,false);

        return ps1 + ps2 + ps3;
    }
};
