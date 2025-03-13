class Solution {
public:
    int SetBitCount(int num) {
        int Cnt = 0;
        while(num) {
            Cnt += num & 1;
            num >>= 1;
        }
        return Cnt;
    }
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int ans = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(SetBitCount(i) == k) ans += nums[i];
        }
        return ans;
    }
};