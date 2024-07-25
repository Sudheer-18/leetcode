class Solution {
    public void merge_sort(int[] nums,int l,int r) {
        if(l<r) {
            int mid = (l+r)/2;
            merge_sort(nums,l,mid);
            merge_sort(nums,mid+1,r);
            merge(nums,l,mid,r);
        }
    }
    public void  merge(int[] arr,int l,int mid,int r) {
        int n1 = mid - l + 1;
        int n2 = r - mid;
        int[] l_arr = new int[n1];
        int[] r_arr = new int[n2];

        for (int x = 0; x < n1; x++) {
            l_arr[x] = arr[l + x];
        }
        for (int x = 0; x < n2; x++) {
            r_arr[x] = arr[mid + 1 + x];
        }

        int i = 0, j = 0, k = l;
        while (i < n1 && j < n2) {
            if (l_arr[i] <= r_arr[j]) {
                arr[k] = l_arr[i];
                i++;
            } else {
                arr[k] = r_arr[j];
                j++;
            }
            k++;
        }

        while (i < n1) {
            arr[k] = l_arr[i];
            i++;
            k++;
        }
        while (j < n2) {
            arr[k] = r_arr[j];
            j++;
            k++;
        }
    }
    public int[] sortArray(int[] nums) {
        int n = nums.length-1;
        merge_sort(nums,0,nums.length-1);
        return nums;
    }
}