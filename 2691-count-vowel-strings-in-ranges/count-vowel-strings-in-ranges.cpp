class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        unordered_set<char> s = {'a', 'e', 'i', 'o', 'u'};
        int n = queries.size();
        vector<int> ps;        
        for(string st : words) {
            if(s.count(st.front()) and s.count(st.back())) {
                ps.emplace_back(1);
            }
            else {
                ps.emplace_back(0);
            }
        }    
        vector<int> pre_sum(ps.size(),0);
        pre_sum[0]  = ps[0] ;
        for(int i = 1;i < ps.size(); i++) {
            pre_sum[i] = ps[i] + pre_sum[i - 1];
        }
        ps.clear();
        for(auto v : queries) {
            int l = v[0];
            int r = v[1];
            int val = 0;
            if(l > 0) {
                val =  pre_sum[r] - pre_sum[l - 1];
            }
            else {
                val = pre_sum[r] ;
            }
            ps.emplace_back(val);
            
        }
        return ps;
    }
};
