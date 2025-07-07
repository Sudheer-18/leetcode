class Solution {
    public int maxEvents(int[][] events) {
        int eventCount = 0;
        int n = events.length;
        Arrays.sort(events,(a,b) -> {
            return a[0] - b[0];
        });
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        int maxDay = 0;
        for(int i=0; i<n; i++) {
            maxDay = Math.max(maxDay,events[i][1]);
        }
        int days=0;
        for(int i=1; days<=maxDay+1; i++) {
            while(pq.size() != 0 && pq.peek() < i) {
                pq.poll();
            }
            while(days < n && events[days][0] == i) {
                pq.offer(events[days][1]);
                days++;
            }
            if(pq.size() != 0 && pq.peek() >= i) {
                pq.poll();
                eventCount++;
            }
            if(pq.size() == 0 && days == n) break;
        }

        return eventCount;
    }
}