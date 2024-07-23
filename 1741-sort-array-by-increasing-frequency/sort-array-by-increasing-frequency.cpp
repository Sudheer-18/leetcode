class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        priority_queue<pair<int,int>> pq;
        map<int,int> mp;
        vector<int>arr;
        int n = nums.size();
        for(int i=0;i<n;i++) {
            mp[nums[i]]++;
        }
        for(auto it=mp.begin();it!=mp.end();it++) {
            pq.push({-it->second,it->first});
        }
        while(!pq.empty()) {
            int x = pq.top().first;
            for(int i=0;i<abs(x);i++) {
                arr.push_back(pq.top().second);
            }
            pq.pop();
        }
        return arr;
    }
};