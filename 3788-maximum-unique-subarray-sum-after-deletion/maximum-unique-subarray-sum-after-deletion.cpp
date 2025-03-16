class Solution {
public:
    int maxSum(vector<int>& nums) {
        set<int> S;
        int n = nums.size();
        for(int i = 0; i < n; i++) S.insert(nums[i]);
        vector<int> V(S.begin(),S.end());
        // for(int i = 0; i < V.size(); i++) cout<<V[i]<<" ";
        int Curr = V[0] , Maxi= V[0];
        for(int i = 1; i < V.size(); i++) {
            Curr = max(Curr+V[i],V[i]);
            Maxi = max(Curr,Maxi);
        }
        return Maxi; 

    }
};