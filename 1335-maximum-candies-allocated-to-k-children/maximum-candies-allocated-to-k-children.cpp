class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        long long low = 1, high = *max_element(candies.begin(), candies.end());
        int ans = 0;
        while (low <= high) {
            long long mid = (low + high) / 2;
            long long ChildCnt = 0;
            for (int val : candies) 
                ChildCnt += (val / mid);

            if (ChildCnt >= k) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};
