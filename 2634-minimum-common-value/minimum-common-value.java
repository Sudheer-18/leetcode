import java.util.HashMap;

class Solution {
    public int getCommon(int[] nums1, int[] nums2) {
        HashMap<Integer, Integer> hm = new HashMap<>();

        for (int val : nums1) {
            hm.put(val, hm.getOrDefault(val, 0) + 1);
        }

        int minVal = Integer.MAX_VALUE;

        for (int val : nums2) {
            if (hm.containsKey(val)) {
                minVal = Math.min(minVal, val);
            }
        }

        return (minVal == Integer.MAX_VALUE) ? -1 : minVal;
    }
}
