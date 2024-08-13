class Solution {
    public List<List<Integer>> combinationSum2(int[] cand, int tar) {
         Arrays.sort(cand);
         int n = cand.length;
         List<Integer> arr = new ArrayList();
         List<List<Integer>> ans = new ArrayList();
         backtracking(cand,tar,arr,ans,n,0,0);
         return ans;
    }
    public void backtracking(int[] nums,int tar,List<Integer>arr,List<List<Integer>> ans,int size,int ind,int sum) {
        if(sum == tar) {
            ans.add(new ArrayList<>(arr));
        }
        if(ind>=size|| sum > tar) return ;
        for(int i=ind;i<size;i++) {
            if(i > ind && nums[i] == nums[i-1]) continue;
            arr.add(nums[i]);
            backtracking(nums,tar,arr,ans,size,i+1,sum+nums[i]);
            arr.remove(arr.size()-1);
        }
        
    }
}