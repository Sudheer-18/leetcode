class Solution {
public:
    int getLeastFrequentDigit(int n) {
        map<int,int> mp;
        while(n != 0) {
            int r = n % 10;
            mp[r]++;
            n /= 10;
        }
        int mini = INT_MAX, res = 0;
        for(auto i : mp) {
            if(i.second < mini) {
                mini = i.second;
                res = i.first;
            }
        }
        return res;
    }
};