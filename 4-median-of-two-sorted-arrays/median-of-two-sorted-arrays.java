class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        double ans = 0;
        int n = nums1.length;
        int m = nums2.length;
        int[] arr = new int[n+m];
        int k=0;
        for(int i=0;i<n;i++) {
            arr[k] = nums1[i];
            k+=1;
        }
        for(int i=0;i<m;i++) {
            arr[k] = nums2[i];
            k+=1;
        }
        Arrays.sort(arr);
       int len = arr.length; 
       if(len%2!=0) {
            int val = (int)len/2;
            ans = arr[val];
       }
       else {
         int val = (int) len/2;
         ans =(double) (arr[val]+arr[val-1])/2;     
       }
       return ans;
    }
}