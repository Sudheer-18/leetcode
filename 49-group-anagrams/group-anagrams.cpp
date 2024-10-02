class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& str) {
        vector<vector<string>>ans;
        if(str.size() == 0) return {{""}};
        if(str.size() == 1) return {str};
        unordered_map<string,vector<string>>mp;
        for(string st : str) {
            string wrd = st; 
            sort(wrd.begin(),wrd.end());
            mp[wrd].push_back(st);
        }
        for(auto it : mp) {
            ans.push_back(it.second);
        }
        return ans;
    }
};