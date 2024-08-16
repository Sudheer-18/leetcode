class Solution {
public:
    int maxDistance(vector<vector<int>>& arr) {
        int minVal = arr[0].front();
        int maxVal = arr[0].back();
        int dist = 0;
        for(int i=1; i<arr.size(); i++){
            dist = max(dist,abs(arr[i].back()-minVal));
            dist = max(dist,abs(maxVal-arr[i].front()));
            minVal = min(minVal,arr[i].front());
            maxVal = max(maxVal,arr[i].back());
        }
        return dist;
    }
};