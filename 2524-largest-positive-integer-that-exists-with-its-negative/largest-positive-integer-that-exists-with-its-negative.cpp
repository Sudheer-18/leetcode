class Solution {
public:
    int findMaxK(vector<int>& nums) {
    unordered_set<int> s(nums.begin(), nums.end());
    int pair = -1;
    for (int num : nums) {
        if (num > 0 && s.count(-num)) {
            pair = max(pair, num);
        }
    }
    return pair;
    }
};