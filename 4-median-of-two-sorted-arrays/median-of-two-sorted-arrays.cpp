class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        nums1.resize(n+m);
        for(int i=0;i<m;++i) {
          nums1[n+i] = nums2[i];
        }
        sort(nums1.begin(),nums1.end());
        n = nums1.size();
        if(n % 2 == 0) {
            int mid = n / 2;
            double ans = (nums1[mid]+nums1[mid-1])/2.0;
            return (double)ans;
        }
        return (double)nums1[n/2];

    }
};