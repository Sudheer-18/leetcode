class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,int>mp;
        set<int> s(arr.begin(),arr.end());
        int rnk = 1;
        for(int ele : s) {
            mp[ele] = rnk;
            rnk++;
        }
        for(int i=0;i<n;i++) {
            arr[i] = mp[arr[i]];
        }
        return arr;
    }
};