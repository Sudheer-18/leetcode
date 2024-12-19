class Solution {
public:
    long long findScore(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<bool> vis(n, false);    
        for (int i = 0; i < n; ++i) {
            pq.push({nums[i], i});
        }
        while (!pq.empty()) {
            auto [pv, ind_val] = pq.top();  
            pq.pop();
            if (vis[ind_val]) continue;
            ans += pv;
            vis[ind_val] = true;
            if (ind_val > 0) vis[ind_val - 1] = true;
            if (ind_val < n - 1) vis[ind_val + 1] = true;
        }
        
        return ans;
    }
};
