class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int ans = 0;
        stack<int>ms;
        int n = nums.size();
        for(int i=0;i<n;i++) {
            if(ms.empty() || nums[ms.top()] > nums[i]) {
                ms.push(i);
            }
        }
        for(int i= n-1;i>=0;i--) {
            while(!ms.empty() && nums[i] >= nums[ms.top()]) {
                ans = max(ans,i-ms.top());
                ms.pop();
            }
        }
        return ans;
    }

};