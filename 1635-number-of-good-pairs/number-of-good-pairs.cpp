class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int i = 0, j = 0, c = 0;
        while (j < nums.size()) {
            while (i < nums.size()) {
                if (nums[i] == nums[j] && i < j) {
                    c += 1;
                }
                i += 1;
            }
            j += 1;
            i = 0; 
        }
        return c;
    }
};
