class Solution {
    public int numOfSubarrays(int[] arr) {
        long oc = 0, PreSUm = 0;
        for(int a : arr){
            PreSUm += a;
            oc += PreSUm % 2;
        }
        oc += (arr.length - oc) * oc;
        return (int)(oc % 1000000007);
    }
}