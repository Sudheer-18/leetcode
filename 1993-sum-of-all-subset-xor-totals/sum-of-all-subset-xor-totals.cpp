class Solution {
public:

    int ans = 0;
    void helper(vector<int>& nums,int n,int idx,vector<int>& V) {
        if(idx >= n) {
            int Xor = 0;
            if(V.size() == 0) return ;
            // for(int i = 0; i < V.size(); i++) {
            //     cout<<V[i]<<" ";
            // }
            // cout<<endl;
            for(int i = 0; i < V.size(); i++) {
                Xor = (Xor ^ V[i]);
            }
            // cout<<"Xor "<<Xor<<endl;
            ans += Xor;
            return ;
        }
        V.push_back(nums[idx]);
        helper(nums,n,idx+1,V);
        V.pop_back();
        helper(nums,n,idx+1,V);
    }
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> V;
        helper(nums,n,0,V);
        return ans;
    }
};