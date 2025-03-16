class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        unordered_map<int, vector<int>> pos;
        for (int i = 0; i < n; i++) {
            pos[nums[i]].push_back(i);
        }
        vector<int> res;
        for (int q : queries) {
            int val = nums[q];
            if (pos[val].size() < 2) {
                res.push_back(-1);
            }
            else {
                int ans = INT_MAX;
                int l = 0, r = pos[val].size() - 1, mid;
                while (l <= r) {
                    mid = (l + r) / 2;
                    if (pos[val][mid] == q) {
                        break;
                    } 
                    else if (pos[val][mid] < q) {
                        l = mid + 1;
                    } 
                    else {
                        r = mid - 1;
                    }
                }
                if (mid > 0) {
                    ans = min(ans, abs(pos[val][mid - 1] - q));
                }
                if (mid < pos[val].size() - 1) {
                    ans = min(ans, abs(pos[val][mid + 1] - q));
                }
                int first = pos[val].front(), last = pos[val].back();
                ans = min(ans, min(q + n - last, first + n - q));
                res.push_back(ans);
            }
        }

        return res;
    }
};
