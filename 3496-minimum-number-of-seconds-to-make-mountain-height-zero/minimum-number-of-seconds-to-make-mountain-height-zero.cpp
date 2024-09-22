class Solution {
public:
    long long minNumberOfSeconds(int mh, vector<int>& wt) {
        long long left = 1, right = LLONG_MAX; 
        while (left < right) {
            long long mid = left + (right - left) / 2;
            if (canReduce(mh, wt, mid)) {
                right = mid; 
            } 
            else {
                left = mid + 1; 
            }
        }
        return left;
    }
    
    bool canReduce(int mh, const vector<int>& wt, long long mt) {
        long long hr = 0;
        for (int time : wt) {
            long long l = 0, h = mh;
            while (l < h) {
                long long mid = (l + h + 1) / 2;
                if (time * mid * (mid + 1) / 2 <= mt) {
                    l = mid;
                } else {
                    h = mid - 1;
                }
            }
            hr += l; 
            if (hr >= mh) return true; 
        }
        return hr >= mh;
    }
};
