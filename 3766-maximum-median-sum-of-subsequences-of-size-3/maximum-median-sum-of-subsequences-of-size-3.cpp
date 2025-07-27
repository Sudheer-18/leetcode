class Solution {
public:
    long long maximumMedianSum(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        sort(begin(nums),end(nums));
        int i = 0, j = n - 1;
        while(i < j) {
            multiset<int> ms;
            ms.insert(nums[i]);
            while(j >= 0 && ms.size() != 3) {
                ms.insert(nums[j]);
                j--;
            }
            auto it = ms.begin();
            advance(it,ms.size()/2);
            ans += *it;
            ms.clear();
            i++;
        }

        return ans;
    }

};