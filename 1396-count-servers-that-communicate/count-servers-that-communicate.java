class Solution {
    public int countServers(int[][] grid) {
        int r = grid.length;
        int c = grid[0].length;
        int[] rc = new int[r];
        int[] cc = new int[c];
        Arrays.fill(rc,0);
        Arrays.fill(cc,0);
        int ans = 0;
        for(int  i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                rc[i]+=grid[i][j];
                cc[j]+=grid[i][j];
            }
        }
        
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                if(grid[i][j] == 1 && (rc[i] > 1 || cc[j] > 1)) ans++;
            }
        }

        return ans;
    }
};