class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        map<int,int> mp;
        int n = nums.size();
        for(int ele : nums) mp[ele]++;
        for(int i = 1; i <= n;i++) {
            if(mp.find(i) == mp.end()) return i; 
        }

        if(mp.find(n+1) == mp.end()) return n + 1;
        return 0;
    }
};