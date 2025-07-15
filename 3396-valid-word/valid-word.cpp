class Solution {
public:
    bool isValid(string word) {
        if (word.length() < 3) return false;
        int vowelCnt = 0, consonantCnt = 0;
        unordered_set<char> vowels = {'a','e','i','o','u','A','E','I','O','U'};
        for (char ch : word) {
            if (!isalnum(ch)) return false; 
            if (isalpha(ch)) {
                if (vowels.count(ch)) {
                    vowelCnt++;
                } 
                else {
                    consonantCnt++;
                }
            }
        }

        return vowelCnt > 0 && consonantCnt > 0;
    }
};
