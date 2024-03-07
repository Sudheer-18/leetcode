class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int cnt=0;
        for(int val:nums) {
            if(val<k) cnt+=1;
        }
        return cnt;
        
    }
};