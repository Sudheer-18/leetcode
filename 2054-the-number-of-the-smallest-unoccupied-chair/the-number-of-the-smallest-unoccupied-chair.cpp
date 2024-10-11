class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int chair = -1;
        int n = times.size();
        priority_queue<int, vector<int>, greater<int>> ac;
        priority_queue<pair<int,int>,vector<pair<int, int>>,greater<pair<int,int>>>pq;
        vector<pair<int, int>> arr;
        for (int i = 0; i < n; ++i) {
            arr.push_back({times[i][0], i});  
        }
        sort(arr.begin(), arr.end()); 
        for (int i = 0; i < n; ++i) {
            ac.push(i);
        }
        for ( auto event : arr) {
            int ar = event.first;
            int fi = event.second;
            while (!pq.empty() && pq.top().first <= ar) {
                ac.push(pq.top().second);
                pq.pop();
            }
            int ch = ac.top();
            ac.pop();
            if (fi == targetFriend) {
                return ch;
            }
            pq.push({times[fi][1], ch});
        }
        
        return 0; 
    }
};
