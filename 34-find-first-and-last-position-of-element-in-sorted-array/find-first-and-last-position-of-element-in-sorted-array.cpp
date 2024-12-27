class Solution {
public:
    vector<int> searchRange(vector<int>& arr, int target) {
        int n = arr.size();
        int low = 0, high = n - 1, mid = 0;
        while (low <= high) {
            mid = (low + high) / 2;
            if (arr[mid] == target) break;
            else if (arr[mid] > target) high = mid - 1;
            else low = mid + 1;
        }

        if (low > high) return {-1, -1};
        int start = mid, end = mid;
        while (start >= 0 && arr[start] == target) --start;
        while (end < n && arr[end] == target) ++end;

        return {start + 1, end - 1};
    }
};
