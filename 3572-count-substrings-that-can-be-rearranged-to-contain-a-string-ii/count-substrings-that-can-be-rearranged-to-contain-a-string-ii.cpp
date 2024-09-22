class Solution {
public:
    long long validSubstringCount(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        map<char,int> mp1;
        map<char,int> mp2;
        for(char ch : word2) {
            mp2[ch]++;
        }
        int j=0;
        long long ans = 0;
        int fnd = 0;
        for(int i=0;i<n;i++) {
            char ch1= word1[i];
            if(mp2.find(ch1) != mp2.end()  && mp1[ch1] < mp2[ch1]) fnd++;
            mp1[ch1]++;
            while(fnd == m) {
                ans += n - i;
                char ch2 = word1[j];
                mp1[ch2]--;
                if(mp2.find(ch2) != mp2.end() && mp1[ch2] < mp2[ch2]) fnd--;
                j++;
            } 
        }
        return ans;
    }
};