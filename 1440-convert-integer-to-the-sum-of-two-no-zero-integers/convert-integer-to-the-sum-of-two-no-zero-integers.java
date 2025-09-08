class Solution {
    private static boolean containsZero(int n) {
        while(n != 0) {
            int r = n % 10;
            if(r == 0) return true;
            n /= 10;
        }
        return false;
    } 
    public int[] getNoZeroIntegers(int n) {
        int s = 1 , e = n;
        while(s <= e) {
            if(containsZero(s) && containsZero(e)) {
                s++;
                e--;
            }
            else if(containsZero(s)) s++;
            else if(containsZero(e)) e--;
            else if(s + e == n) return new int[]{s,e}; 
            else if(s + e < n) s++;
            else e--;
        }
        return new int[]{};
    }
}