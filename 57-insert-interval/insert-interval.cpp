class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int a = newInterval.front();
        int b = newInterval.back();
        int i = 0, n = intervals.size();
        while (i < n && intervals[i][1] < a) {
            ans.push_back(intervals[i]);
            i++;
        }
        while (i < n && intervals[i][0] <= b) {
            a = min(a, intervals[i][0]);
            b = max(b, intervals[i][1]);
            i++;
        }
        ans.push_back({a, b});
        while (i < n) {
            ans.push_back(intervals[i]);
            i++;
        }
        
        return ans;
    }
};
