class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        map<string,int>mp;
        // vector<string> s;
        for(auto sd : arr) {
            mp[sd]++;
        }
        for(auto ele : arr ) {
            if(mp[ele] == 1 ) {
                k-=1;
                if(k==0) return ele;
            }
        }
        // if(s.size()<k) return "";
        return "";
     }
};