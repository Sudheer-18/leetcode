class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        vector<int>pre;
        int ps=0;
        for(int i=0;i<gain.size();i++)
        {
            ps+=gain[i];
            pre.push_back(ps);
        }
        for(int val : pre) {
            if(val>0)  return *max_element(pre.begin(),pre.end());
        }
        return 0;
    }
};