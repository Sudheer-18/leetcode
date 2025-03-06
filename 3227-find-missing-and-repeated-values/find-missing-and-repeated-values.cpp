class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        map<int, int> mp;
        int n = grid.size();
        int N = n * n;
        int sum = 0, r = 0, m = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                mp[grid[i][j]]++;
            }
        }
        for (auto& it : mp) {
            sum += it.first;
            if (it.second > 1) {
                r = it.first;
            }
        }
        int es = (N * (N + 1)) / 2;
        m = es - sum;
        return {r, m};
    }
};
