class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char,int> mp;
        priority_queue<int>pq;
        int n = word.length();
        for(int i=0;i<n;i++) {
            mp[word[i]-'a']++;
        }
        for(auto it=mp.begin();it!=mp.end();it++) {
            pq.push(it->second);
        }
        int tot_push = 0,ind = 0;
        while(!pq.empty()) {
            tot_push +=(1+(ind/8))*pq.top();
            pq.pop();
            ind++;
        }
        return tot_push;
    }
};