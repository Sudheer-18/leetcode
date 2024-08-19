class Solution {
    public int minSteps(int n) {
        int st = 0,cur = 1,cb = 0;
        while(cur != n) {
            if(n%cur == 0)  {
                cb = cur;
                cur+=cb;
                st+=2;
            }
            else {
                cur+=cb;
                st+=1;
            }
           
        } 
        return st;
    }
}