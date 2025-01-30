class Solution {
public:
    vector<string> ans;
    void fun(unordered_map<char,string>& mp, int i, string s, string dig, int n) {
        if(i >= n) {
            ans.push_back(s);
            return;
        }
        string temp = mp[dig[i]];
        for(char ch : temp) {
            fun(mp, i + 1, s + ch, dig, n);
        }
    }
    
    vector<string> letterCombinations(string digits) {
        unordered_map<char,string> mp;
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