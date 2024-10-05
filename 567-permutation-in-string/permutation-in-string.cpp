class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();
        if (n1 > n2) return false;  
        vector<int> sf1(26, 0), sf2(26, 0);
        for (int i = 0; i < n1; i++) {
            sf1[s1[i] - 'a']++;
            sf2[s2[i] - 'a']++;
        }
        if (sf1 == sf2) return true;
        for (int i = n1; i < n2; i++) {
            sf2[s2[i] - 'a']++;
            sf2[s2[i - n1] - 'a']--;
            if (sf1 == sf2) return true;
        }
        
        return false;
    }
};
