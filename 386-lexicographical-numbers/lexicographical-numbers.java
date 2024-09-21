class Solution {
    public List<Integer> lexicalOrder(int n) {
        List<Integer> list = new ArrayList<>();
        String[] s = new String[n];
        for(int i = 1; i <= n ; i++){
            s[i-1] = Integer.toString(i);
        }
        Arrays.sort(s);
        for(int i = 0 ; i < n ; i++){
            list.add(Integer.parseInt(s[i]));
        }
        return list;
    }
}