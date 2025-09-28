class Solution {
public:
    string majorityFrequencyGroup(string s) {
        string ans = "";
        int n = s.size();
        if(n == 1) return s;
        unordered_map<int, vector<char>> mp1;
        map<char,int> mp2;
        for(char ch : s) mp2[ch]++;
        for(auto i : mp2) {
            mp1[i.second].push_back(i.first);
        }
        for(auto i : mp1) {
            cout<<i.first<<" ";
            for(char ch : i.second) cout<<ch<<" ";
            cout<<endl;
        }
        int maxi = 0,key = 0;
        for(auto i : mp1) maxi = max(maxi,(int)i.second.size());
        for(auto i : mp1) {
            if((int)i.second.size() == maxi && key < i.first) key = i.first;
        }
        for(char ch : mp1[key]) ans += ch;
        return ans;
    }
};