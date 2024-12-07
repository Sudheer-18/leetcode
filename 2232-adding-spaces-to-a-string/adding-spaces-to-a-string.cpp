class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans = "";
        map<int,int>mp;
        for(int ele : spaces) mp[ele]++;
        for(int i = 0; i < s.size();i++) {
            if(mp.find(0) != mp.end()) {
                ans += " ";
                mp.erase(0);
            }
            if(mp.find(i+1) != mp.end()) {
                ans += s[i]; 
                ans += " ";
            }
            else {
                ans += s[i];
            }
        }
        return ans;
    }
};