class Solution {
public:
    string convert(string s, int numRows) {
    if (numRows == 1) return s;  
    string res = "";
    int cl = 2 * (numRows - 1); 
    for (int row = 0; row < numRows; row++) {
        for (int i = row; i < s.length(); i += cl) {
            res += s[i];  
            int di = i + cl - 2 * row;
            if (row != 0 && row != numRows - 1 && di < s.length()) {
                res += s[di];
            }
        }
    }
    return res;
}
};