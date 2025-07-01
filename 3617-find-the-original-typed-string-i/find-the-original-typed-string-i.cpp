class Solution {
public:
    int possibleStringCount(string word) {
        int cnt = 1;
        int n = word.size();
        int i = 0;
        while (i < n) {
            int j = i + 1;
            while (j < n && word[j] == word[i]) {
                j++;
            }
            int length = j - i;
            if (length > 1) {
                cnt += length - 1; 
            }
            
            i = j; 
        }
        return cnt;
    }
};
