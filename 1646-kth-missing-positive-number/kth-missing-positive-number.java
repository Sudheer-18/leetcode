class Solution {
  public static int findKthPositive(int[] arr, int k) {
        int n = arr.length;
        HashMap<Integer, Integer> hm = new HashMap<>();
        for (int i = 0; i < n; i++) {
            hm.put(arr[i], hm.getOrDefault(arr[i], 0) + 1);
        }
        int val = 1, ans = 0;
        while (k > 0) {
            if (!hm.containsKey(val)) {
                ans = val;
                k--; 
            }
            val++; 
        }
        return ans;
        // System.out.println(ans); 
    }
}