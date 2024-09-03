class Solution {
public:
    int getLucky(string s, int k) {
        int ans = 0;
        string st = "";
        for (char ch : s) {
            int val = ch - 'a' + 1;
            if (val >= 0) {
                st += to_string(val);
            } else {
                st += "0";
            }
        }
       while(k>0) {
        int temp = 0;
        for(char ch : st) {
            temp+=ch-'0';
        }
        st = to_string(temp);
        k-=1;
       }
       return stoi(st);
    }
};
