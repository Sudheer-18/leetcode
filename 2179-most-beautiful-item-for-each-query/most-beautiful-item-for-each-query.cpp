class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& item, vector<int>& q) {
        int n = item.size();
        int m = q.size();
        vector<int> ans;
        sort(item.begin(), item.end(), [](vector<int>& a, vector<int>& b) {
            return a[0] < b[0];
        });
        vector<int> maxBeauty(n);
        maxBeauty[0] = item[0][1];
        for (int i = 1; i < n; ++i) {
            maxBeauty[i] = max(maxBeauty[i - 1], item[i][1]);
        }
        for (int i = 0; i < m; i++) {
            int price = q[i];
            int left = 0, right = n - 1, pos = -1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (item[mid][0] <= price) {
                    pos = mid;
                    left = mid + 1;
                } 
                else {
                    right = mid - 1;
                }
            }
            if (pos == -1) {
                ans.push_back(0); 
            } 
            else {
                ans.push_back(maxBeauty[pos]);
            }
        }

        return ans;
    }
};
