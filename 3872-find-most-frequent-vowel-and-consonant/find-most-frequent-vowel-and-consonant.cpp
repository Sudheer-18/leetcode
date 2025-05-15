class Solution {
public:
    int maxFreqSum(string s) {
        map<char,int> mp;
        for(char ch : s) {
            mp[ch]++;
        }
        set<char> st = {'a','e','i','o','u'};
        int Vow_Cnt = 0, Con_Cnt = 0;
        for(auto i : mp) {
            if(st.count(i.first)) {
                Vow_Cnt = max(i.second,Vow_Cnt);
            }
            else {
                 Con_Cnt = max(i.second, Con_Cnt);
            }
        }

        return Vow_Cnt + Con_Cnt;
    }
};