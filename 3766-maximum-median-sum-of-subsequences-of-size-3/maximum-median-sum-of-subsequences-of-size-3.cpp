class Solution {
public:
    long long maximumMedianSum(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        sort(begin(nums),end(nums));
        int i = 0, j = n - 1;
        while(i < j) {
            vector<int> V;
            V.push_back(nums[i]);
            while(j >= 0 && V.size() != 3) {
                V.push_back(nums[j]);
                j--;
            }
            sort(begin(V),end(V));
            ans += V[1];
            V.clear();
            i++;
        }

        return ans;
    }

};