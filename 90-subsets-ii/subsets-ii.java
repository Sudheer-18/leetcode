
class Solution {
    List<List<Integer>> al = new ArrayList<>();
    HashMap<List<Integer>, Integer> hm = new HashMap<>();
    public void helper(int[] nums, List<Integer> list, int idx, int n) {
        if (idx >= n) {
            List<Integer> temp = new ArrayList<>(list);
            if (!hm.containsKey(temp)) {
                al.add(temp);
                hm.put(temp, hm.getOrDefault(temp, 0) + 1);
            }
            return;
        }
        list.add(nums[idx]);
        helper(nums, list, idx + 1, n);
        list.remove(list.size() - 1); 
        helper(nums, list, idx + 1, n);
    }
    
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        Arrays.sort(nums); 
        List<Integer> list = new ArrayList<>();
        helper(nums, list, 0, nums.length);
        return al;
    }
}
