class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        vector<int> res;
        int r_sum = 0;
        int m = rolls.size();
        for(int i=0;i<m;i++) r_sum+=rolls[i];
        int val  = mean*(m+n) - r_sum;
        if(val > n*6 || val < n) return {};
        int num = val / n;
        int rem  = val%n;
        for(int i=0;i<rem;i++) res.push_back(num+1);
        for(int i=rem;i<n;i++) res.push_back(num);

        return res;
    }
};