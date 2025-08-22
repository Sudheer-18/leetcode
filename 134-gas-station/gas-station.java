class Solution {
    public int canCompleteCircuit(int[] gas, int[] cost) {
        int size = gas.length;
        int tot = 0 , tank = 0, st = 0;
        for(int i=0; i<size; i++) {
            int dif = gas[i] - cost[i];
            tot += dif;
            tank += dif;
            if(tank < 0) {
                st = i + 1;
                tank = 0;
            }
        }
        if(tot < 0) return -1;
        return st;
    }
}