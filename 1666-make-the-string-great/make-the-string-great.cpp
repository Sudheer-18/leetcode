class Solution {
public:
    string makeGood(string s) {
        int n = s.size();
        for (int i = 0; i < n - 1; ) {
            if (abs(int(s[i]) - int(s[i + 1])) == 32) {
                s.erase(i, 2);
                if (i > 0) {
                    i--;
                }
                n -= 2; 
            } else {
                i++;
            }
        }
        return s;
    }
};