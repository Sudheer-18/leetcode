class Solution {
public:
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
        priority_queue<int> pq;
        for (int i = 0; i < grid.size(); i++) {
            sort(grid[i].rbegin(), grid[i].rend()); 
            for (int j = 0; j < min((int)grid[i].size(), limits[i]); j++)  pq.push(grid[i][j]);
        }
        long long sum = 0;
        while (k-- && !pq.empty()) sum += pq.top(), pq.pop();
        return sum;
    }
};