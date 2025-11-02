class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int mini = *min_element(begin(nums),end(nums));
        int maxi = *max_element(begin(nums),end(nums));
        vector<int> ans;
        unordered_map<int,int> mp;
        for(int x : nums) mp[x]++;
        for(int i=mini; i<=maxi; i++) {
            if(mp.find(i) == mp.end()) ans.emplace_back(i);
        }
        return ans;
    }
};