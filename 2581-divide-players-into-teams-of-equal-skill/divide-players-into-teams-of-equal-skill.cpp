class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        long long ans = 0;
        int n = skill.size();
        if(n % 2 != 0) return -1;
        sort(skill.begin(), skill.end());
        int ts_sum = skill[0] + skill[n-1];
        for(int i = 0; i < n / 2; i++) {
            if(skill[i] + skill[n-1-i] != ts_sum) {
                return -1; 
            }
            ans += (long long)(skill[i] * skill[n-1-i]);
        }
        
        return ans;
    }
};
