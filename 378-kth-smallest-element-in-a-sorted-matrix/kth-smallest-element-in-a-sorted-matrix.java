class Solution {
    public int kthSmallest(int[][] matrix, int k) {
        PriorityQueue<Integer> PQ = new PriorityQueue<>();
        int n = matrix.length;
        int m = matrix[0].length;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                PQ.offer(matrix[i][j]);
            }
        }
        while(k != 1) {
            PQ.poll();
            k--;
        }
        return PQ.peek();
    }
}