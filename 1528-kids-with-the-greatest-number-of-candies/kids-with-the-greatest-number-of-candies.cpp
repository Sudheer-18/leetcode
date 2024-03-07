#include<vector>
class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int len=candies.size();
        vector<bool>v1;
        bool t=true,f=false;
        int max=*max_element(candies.begin(),candies.end());
        for(int i=0;i<len;i++)
        {
            if(candies[i]+extraCandies>=max)
            {
                v1.push_back(t);
            }
            else {
                v1.push_back(f);
            }
        }
        return v1;
        
    }
};