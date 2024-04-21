class Solution {
public:
    int maximumWealth(vector<vector<int>>& arr) {
        int max=0;
        int sum=0;
        for(int i=0;i<arr.size();i++) {
            sum=0;
            for(int j=0;j<arr[i].size();j++) {
                sum+=arr[i][j];
            }
            if(max<sum) max=sum;
        }
        return max;
        
    }
};