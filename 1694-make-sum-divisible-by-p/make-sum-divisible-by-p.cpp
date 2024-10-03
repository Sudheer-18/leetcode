class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int pre_sum = 0;
        int n = nums.size();
        unordered_map<int,int>mp;
        int ans = n;
        for(int i=0;i<n;i++) {
            pre_sum = (pre_sum+nums[i])%p;
        }
        if(pre_sum == 0) return 0;
        int r = pre_sum % p;
        mp[0] = -1;
        pre_sum = 0;
        for(int i= 0;i<n;i++) {
           pre_sum = (pre_sum+nums[i])%p;
           int rem = (pre_sum - r + p)%p;
           if(mp.find(rem) != mp.end()) {
            int len = i - mp[rem];
            ans = min(ans,len);
           }
           mp[pre_sum] = i;
        }
       if(ans  == n) return -1;
       return ans;
    }
};