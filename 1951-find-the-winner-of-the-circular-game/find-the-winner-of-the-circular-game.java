class Solution {
    public int findTheWinner(int n, int k) {
        ArrayList<Integer> arr = new ArrayList<Integer>();
        for(int i=1;i<=n;i++) arr.add(i);
        int st = 0;
        while(arr.size() > 1) {
            st = (st+(k-1))%arr.size();
            arr.remove(st);
        }
        return arr.get(0);
    }
}