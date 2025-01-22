class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int min_len = INT_MAX;
        int ps = 0, i = 0 , j = 0;
        while(i < nums.size()) {
            ps += nums[i];
            while(ps >= target) {
                min_len = min(min_len,i - j + 1);
                ps -= nums[j];
                j++;
            }
            i++;
        }
        if(min_len == INT_MAX) return 0;
        return min_len;
    }
};