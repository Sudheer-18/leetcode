class Solution {
    public int mostBooked(int n, int[][] meetings) {
        int size = meetings.length;
        Arrays.sort(meetings, (a, b) -> Integer.compare(a[0], b[0]));
        PriorityQueue<long[]> pq = new PriorityQueue<>((a, b) -> Long.compare(a[0], b[0]));
        int[] roomUsed = new int[n];
        long[] endTime = new long[n];
        for (int i = 0; i < size; i++) {
            long start = meetings[i][0];
            long end = meetings[i][1];
            long duration = end - start;
            while (!pq.isEmpty() && pq.peek()[0] <= start) {
                pq.poll();
            }
            int room = -1;
            long minEnd = Long.MAX_VALUE;
            for (int r = 0; r < n; r++) {
                if (endTime[r] <= start) {
                    room = r;
                    break;
                }
                if (endTime[r] < minEnd) {
                    minEnd = endTime[r];
                    room = r;
                }
            }

            if (endTime[room] <= start) {
                endTime[room] = start + duration;
            } 
            else {
                start = endTime[room];
                endTime[room] = start + duration;
            }
            roomUsed[room]++;
            pq.offer(new long[]{endTime[room], room});
        }
        int maxRoom = 0;
        for (int i = 1; i < n; i++) {
            if (roomUsed[i] > roomUsed[maxRoom]) {
                maxRoom = i;
            }
        }
        return maxRoom;
    }
}
