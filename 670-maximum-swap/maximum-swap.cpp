class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num); 
        int n = s.size();
        vector<int> maxIndex(n);  
        int maxPos = n - 1;
        maxIndex[maxPos] = maxPos;
        for (int i = n - 2; i >= 0; --i) {
            if (s[i] > s[maxPos]) {
                maxPos = i;
            }
            maxIndex[i] = maxPos;
        }

        for (int i = 0; i < n; ++i) {
            if (s[i] < s[maxIndex[i]]) {
                swap(s[i], s[maxIndex[i]]);
                break;
            }
        }
        return stoi(s);
    }
};
