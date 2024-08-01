class Solution {
public:
    int countSeniors(vector<string>& details) {
        int cnt = 0;
        for(auto st : details) {
            string s = st.substr(11, 2);
                int num = stoi(s);
                if(num > 60) cnt += 1;
        }
        return cnt;
    }
};
