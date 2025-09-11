class Solution {
public:
    string sortVowels(string s) {
        vector<char> v;
        set<char> st = {'a','e','i','o','u','U','O','E','I','A'};
        for(int i=0; i<s.size(); i++) {
            if(st.find(s[i]) != st.end()) {
                v.push_back(s[i]);
            }
        }
        sort(begin(v),end(v));
        int k=0;
        for(int i=0; i<s.size(); i++) {
            if(st.find(s[i]) != st.end()) {
                s[i] = v[k];
                k++;
            }
        }
        return s;
    }
};