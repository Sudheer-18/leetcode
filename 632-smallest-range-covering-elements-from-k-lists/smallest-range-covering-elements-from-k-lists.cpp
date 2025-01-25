class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        multimap<int, pair<int, int>> mp;
        int k = nums.size();
        int maxVal = INT_MIN;
        long long maxi = INT_MIN;
        for (int i = 0; i < k; i++) {
            mp.insert({nums[i][0], {i, 0}});
            maxVal = max(maxVal, nums[i][0]);
            if(maxi < nums[i].size()) maxi = nums[i].size();
        }
        int rs = 0, re = INT_MAX;
        while (maxi--) {
            auto it = mp.begin();
            int minVal = it->first;
            int li = it->second.first;
            int ind = it->second.second;
            if (maxVal - minVal < re - rs || (maxVal - minVal == re - rs && minVal < rs)) {
                rs = minVal;
                re = maxVal;
            }
            mp.erase(it);
            if (ind + 1 < nums[li].size()) {
                int val = nums[li][ind + 1];
                mp.insert({val, {li, ind + 1}});
                maxVal = max(maxVal, val);
            } 
            else {
                break;
            }
        }
        return {rs, re};
    }
};
