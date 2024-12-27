class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& arr) {
        int n = arr.size();
        int max_val = 0; 
        int max_i = arr[0]; 
        for (int j = 1; j < n; ++j) {
            max_val = max(max_val, max_i + arr[j] - j);
            max_i = max(max_i, arr[j] + j);
        }
        
        return max_val;
    }
};
