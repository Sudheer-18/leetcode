class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(begin(nums), end(nums));
        int i = 0;
        for(int ele : nums) {
            if(ele - nums[i] > 2 * k) {
                i++;
            }
        }
        return nums.size() - i;
    }
};
