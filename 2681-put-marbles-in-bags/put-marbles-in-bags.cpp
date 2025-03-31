class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        priority_queue<int> MaxPq;
        priority_queue<int,vector<int>,greater<int>> MinPq;
        for(int i=0; i<n-1; i++) {
            MaxPq.push(weights[i]+weights[i+1]);
            MinPq.push(weights[i]+weights[i+1]);
        }
        long long MaxSum = 0, MinSum = 0;
        for(int i=0; i<k-1; i++) {
            MaxSum += MaxPq.top();
            MinSum += MinPq.top();
            MaxPq.pop();
            MinPq.pop();
        }
        return MaxSum - MinSum;
    }
};