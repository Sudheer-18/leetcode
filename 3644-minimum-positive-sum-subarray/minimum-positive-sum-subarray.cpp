class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        int min_val = INT_MAX;
        for (int i = 0; i < n; ++i) {
            int ps = 0;
            for (int j = i; j < n && j - i + 1 <= r; ++j) {
                ps += nums[j];
                if (j - i + 1 >= l && ps > 0) {
                    min_val = min(min_val, ps);
                }
            }
        }
        return min_val == INT_MAX ? -1 : min_val;
    }
};
