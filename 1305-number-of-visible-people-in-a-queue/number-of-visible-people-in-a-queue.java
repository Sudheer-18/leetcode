class Solution {
    public int[] canSeePersonsCount(int[] heights) {
        int N = heights.length;
        Stack<Integer> St = new Stack<>();
        int[] Ans = new int[N];
        for(int i=N-1; i>=0; i--) {
            int CanSee = 0;
            int val = heights[i];
            while(!St.isEmpty() && St.peek() <= val) {
                St.pop();
                CanSee++;
            }
            if(St.isEmpty()) {
                Ans[i] = CanSee;
            }
            else {
                Ans[i] = CanSee + 1;
            }
            St.push(val);
        }
        return Ans;
    }
}