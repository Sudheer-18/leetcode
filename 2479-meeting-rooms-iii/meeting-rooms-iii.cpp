class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        int size = meetings.size();
        sort(begin(meetings), end(meetings));
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        vector<int> roomUsed(n, 0);    
        vector<long long> endTime(n, 0);  
        for (int i = 0; i < size; ++i) {
            long long start = meetings[i][0];
            long long end = meetings[i][1];
            int duration = end - start;
            while (!pq.empty() && pq.top().first <= start) {
                pq.pop(); 
            }
            int room = -1;
            long long minEnd = LLONG_MAX;
            for (int r = 0; r < n; ++r) {
                if (endTime[r] <= start) {
                    room = r;
                    break;
                }
                if (endTime[r] < minEnd) {
                    minEnd = endTime[r];
                    room = r;
                }
            }
            if (endTime[room] <= start) {
                endTime[room] = start + duration;
            } else {
                start = endTime[room];
                endTime[room] = start + duration;
            }

            roomUsed[room]++;
            pq.push({endTime[room], room});
        }
        int maxRoom = 0;
        for (int i = 1; i < n; i++) {
            if (roomUsed[i] > roomUsed[maxRoom]) {
                maxRoom = i;
            }
        }
        return maxRoom;
    }
};
