class Solution {
    public int longestCommonPrefix(int[] arr1, int[] arr2) {
        HashSet<Integer> hs = new HashSet<>();
        int res = 0;
        for(int num : arr1) {
            while(!hs.contains(num) && num > 0) {
                hs.add(num);
                num = num/10;
            }
        }
        for(int num : arr2) {
            while(!hs.contains(num) && num > 0) {
                num = num/10;
            }
            if(num > 0) {
                res = Math.max(res,(int)Math.log10(num)+1);
            }
        }
        return res;
    }
}