class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        set<int> s;
        int sum  = 0;
        int ps = 0;
        for(int num:nums) {
            sum = (sum + num) % k;
            if(s.find(sum) != s.end()) return true;
            s.insert(ps);
            ps = sum;
        }
        return false;
    }
};