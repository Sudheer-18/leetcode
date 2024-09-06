class Solution {
public:
    vector<string> ans;
    void fun(map<char,string>& mp, int i, string s, string dig, int n) {
        if(i >= n) {
            ans.push_back(s);
            return;
        }
        string temp = mp[dig[i]];
        for(int j = 0; j < temp.length(); j++) {
            fun(mp, i + 1, s + temp[j], dig, n);
        }
    }
    
    vector<string> letterCombinations(string digits) {
        map<char,string> mp;
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";
        
        if(digits == "") return {};
        fun(mp, 0, "", digits, digits.length());
        return ans;
    }
};
