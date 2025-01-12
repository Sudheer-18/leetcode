class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int n = words.size();
        int ans = 0;
        for(string str : words) {
            int i = 0;
            int cnt = 0;
            for(char ch : str) {
                if(ch == pref[i]) {
                    cnt++;
                }
                else {
                    break;
                }
                i++;
            }
            if(cnt == pref.size()) ans++;
        }
        return ans;
    }
};