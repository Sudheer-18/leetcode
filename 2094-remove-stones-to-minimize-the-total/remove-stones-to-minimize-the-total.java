class Solution {
    public int minStoneSum(int[] p, int k) {
        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
        for(int ele : p) pq.offer(ele);
        while(k-- > 0) {
            int maxElement = pq.poll();
            int reducedElement = maxElement - (maxElement / 2);
            pq.offer(reducedElement);
        }
        int sum = 0;
        while(!pq.isEmpty()) {
            sum+=pq.peek();
            pq.poll();
        }
        return sum;
    }
}