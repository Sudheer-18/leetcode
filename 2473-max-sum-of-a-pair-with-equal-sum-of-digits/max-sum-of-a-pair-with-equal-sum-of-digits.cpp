class Solution {
public:
    int DigitSum(int n) {
        int DigitSum = 0, r;
        while(n != 0) {
            r = n % 10;
            DigitSum += r;
            n /= 10;
        }
        return DigitSum;
    }
    int maximumSum(vector<int>& nums) {
        int n = nums.size();
        map<int,vector<int>> mp;
        for(int i = 0; i < n; i++) {
            mp[DigitSum(nums[i])].push_back(nums[i]);
        }
        int cnt = 0;
        int MaxSum = 0;
        for(auto it : mp) {
            int size = it.second.size();
            int sum = 0;
            sort(it.second.begin(),it.second.end());
            if(size >= 2) sum = it.second[size - 1] + it.second[size - 2];
            else {
                cnt++;
            }
            MaxSum = max(MaxSum,sum);
        }
        if(cnt == mp.size()) return -1;
        return MaxSum;
    }


/* 
    7 - 7 43
    4 - 13
    9 - 18 36

*/
    
};