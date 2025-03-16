class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        unordered_map<int, vector<int>> pos;
        for (int i = 0; i < n; i++) {
            pos[nums[i]].push_back(i);
        }
        for (int i = 0; i < queries.size(); i++) {
            int val = nums[queries[i]];
            if (pos[val].size() < 2) {
                queries[i] = -1;
            }
            else {
                int ans = INT_MAX;
                int l = 0, r = pos[val].size() - 1, mid;
                while (l <= r) {
                    mid = (l + r) / 2;
                    if (pos[val][mid] == queries[i]) {
                        break;
                    } 
                    else if (pos[val][mid] < queries[i]) {
                        l = mid + 1;
                    } 
                    else {
                        r = mid - 1;
                    }
                }
                if (mid > 0) {
                    ans = min(ans, abs(pos[val][mid - 1] - queries[i]));
                }
                if (mid < pos[val].size() - 1) {
                    ans = min(ans, abs(pos[val][mid + 1] - queries[i]));
                }
                int first = pos[val].front(), last = pos[val].back();
                ans = min(ans, min(queries[i] + n - last, first + n - queries[i]));
                queries[i] = ans;
            }
        }

        return queries;
    }
};
