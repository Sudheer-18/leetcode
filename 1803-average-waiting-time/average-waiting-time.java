class Solution {
    public double averageWaitingTime(int[][] arr) {
        int n = arr.length;
        double tw = 0;
        int ct = 0;
        for (int[] ar : arr) {
            int a = ar[0];
            int c = ar[1];
            ct = Math.max(ct, a) + c;
            tw += ct - a;
        }

        return tw / n;
    }
}
