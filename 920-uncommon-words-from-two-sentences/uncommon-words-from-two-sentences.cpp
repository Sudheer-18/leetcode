class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string> ans;
        unordered_map<string, int> mp;
        string st = "";
        for (char ch : s1) {
            if (ch == ' ') {
                mp[st]++;
                st = "";
            } else {
                st += ch;
            }
        }
        if (!st.empty()) mp[st]++; 

        st = "";
        for (char ch : s2) {
            if (ch == ' ') {
                mp[st]++;
                st = "";
            } else {
                st += ch;
            }
        }
        if (!st.empty()) mp[st]++; 

        for (auto it = mp.begin(); it != mp.end(); it++) {  
            if (it->second == 1) {
                ans.push_back(it->first);
            }
        }

        return ans;
    }
};
