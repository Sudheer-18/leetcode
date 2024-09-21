class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> arr;
        vector<string> s(n);
        for(int i=1;i<=n;i++) {
            s[i-1] = to_string(i);
        }
        sort(s.begin(),s.end());
        for(int i=0;i<n;i++) {
            arr.push_back(stoi(s[i]));
        }
        return arr;
    }
};