class Solution {
    public void helper(List<Integer> nums, List<Integer> arr, List<List<Integer>> ans, int k, int n, int ind, int sum) {
        if (arr.size() > k) return;
        if (sum == n && arr.size() == k) {
            ans.add(new ArrayList<>(arr));
            return;
        }
        for (int i = ind; i < nums.size(); i++) {
            arr.add(nums.get(i));
            helper(nums, arr, ans, k, n, i + 1, sum + nums.get(i));
            arr.remove(arr.size() - 1);
        }
    }

    public List<List<Integer>> combinationSum3(int k, int n) {
        List<List<Integer>> ans = new ArrayList<>();
        List<Integer> arr = new ArrayList<>();
        List<Integer> nums = new ArrayList<>();
        for (int i = 1; i <= 9; i++) {
            nums.add(i);
        }
        helper(nums, arr, ans, k, n, 0, 0);
        return ans;
    }
}
