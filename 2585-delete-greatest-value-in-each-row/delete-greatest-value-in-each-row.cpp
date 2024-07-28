class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
      unordered_map<int,  priority_queue<int>> mp;
      int n = grid.size();
      int m = grid[0].size();
      for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            mp[i].push(grid[i][j]);
        }
      }
      int sum = 0;
      for(int i=0;i<m;i++) {
        int max_val = 0;
        for(int i=0;i<n;i++) {
            int temp = mp[i].top();
            mp[i].pop();
            max_val = max(temp,max_val);
        }
        sum+=max_val;
      }
      return sum;
    }
};