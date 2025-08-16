class Solution {
public:
    int maximum69Number (int num) {
        bool flag = false;
        string s = to_string(num);
        int i = 0;
        string res = "";
        while(i < s.size()) {
            if(s[i] == '6' && !flag) {
                res += '9';
                flag = true;
            } 
            else res += s[i];
            i++;
        }
        return stoi(res);
    }
};