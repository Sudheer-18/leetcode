#include <vector>
#include <map>
#include <algorithm>

class Solution {
public:
    std::vector<int> relativeSortArray(std::vector<int>& arr1, std::vector<int>& arr2) {
        vector<int> ans;
        map<int, int> mp;
        for(int i = 0; i < arr1.size(); i++) {
            mp[arr1[i]]++;
        }
        for(int ele : arr2) {
            if(mp.find(ele) != mp.end()) {
                while(mp[ele] > 0) {
                    ans.push_back(ele);
                    mp[ele]--;
                }
                mp.erase(ele); 
            }
        }
    
        vector<int> rest;
        for(auto it = mp.begin(); it != mp.end(); ++it) {
            while(it->second > 0) {
                rest.push_back(it->first);
                it->second--;
            }
        }
    
        // sort(rest.begin(), rest.end());
        ans.insert(ans.end(), rest.begin(), rest.end());
        
        return ans;
    }
};
