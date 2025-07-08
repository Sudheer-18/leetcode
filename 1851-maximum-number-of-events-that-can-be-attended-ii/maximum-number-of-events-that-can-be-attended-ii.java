class Solution {

    private int Helper(int[][] events, int cs) {
        int s=0, e=events.length-1;
        int res = -1;
        while(s <= e) {
            int mid = (s+e)/2;
            if(events[mid][1] < cs) {
                res = mid;
                s = mid + 1;
            }
            else {
                e = mid - 1 ;
            }
        }
        return res;
    }

    public int maxValue(int[][] events, int k) {
        int n = events.length;
        Arrays.sort(events, (a,b)-> a[1] - b[1]);
        int[][] dp = new int[n+1][k+1];
        for(int i=1; i<=n; i++) {
            int[] arr = events[i-1];
            int pre = Helper(events,arr[0]);
            for(int j=1; j<=k; j++) {
                dp[i][j] = Math.max(dp[i-1][j], dp[pre+1][j-1]+arr[2]);
            }
        }
        return dp[n][k];
    }
}