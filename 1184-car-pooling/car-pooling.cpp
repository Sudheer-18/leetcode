class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        int n = trips.size();
        for(int i=0;i<n;i++) {
            pq.push({trips[i][1],trips[i][0]});
            pq.push({trips[i][2],-trips[i][0]});
        }
        int ch = 0;
        while(!pq.empty()) {
            ch+=pq.top().second;
            pq.pop();
            if(ch > capacity) return false;
        }
        return true;
    }
};