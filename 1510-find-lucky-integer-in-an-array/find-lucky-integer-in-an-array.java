class Solution {
    public int findLucky(int[] arr) {
        Map<Integer, Integer> mp = new HashMap<>();
        for(int x : arr) mp.put(x,mp.getOrDefault(x,0)+1);
        int maxi = -1;
        for(Map.Entry<Integer,Integer> entry : mp.entrySet()) {
            int k = entry.getKey();
            int v = entry.getValue();
            if(k == v) {
                maxi = Math.max(maxi,k);
            }
        }
        return maxi;
    }
}