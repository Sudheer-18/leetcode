class Solution {
public:
    int findLHS(vector<int>& nums) {
        multiset<int> ms(nums.begin(), nums.end());
        int ans = 0;
        for (int num : ms) {
            if (ms.count(num + 1) > 0) {
                int total = ms.count(num) + ms.count(num + 1);
                ans = max(ans, total);
            }
            auto it = ms.upper_bound(num);
            if (it == ms.end()) break;
            num = *it;
        }
        return ans;
    }
};
