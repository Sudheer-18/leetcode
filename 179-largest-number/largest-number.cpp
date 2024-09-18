class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> numStrs;
        for(int n : nums) {
            numStrs.push_back(to_string(n));
        }
        sort(numStrs.begin(), numStrs.end(), [](string &a, string &b) {
            return a + b > b + a; 
        });
        string res;
        for(string &s : numStrs) {
            res += s;
        }
        return res[0] == '0' ? "0" : res;
    }
};
