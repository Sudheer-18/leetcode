class Solution {
public:
    bool helper(int x) {
        while(x != 0) {
            int r = x & 1;
            if(!r) return false;
             x = x  >> 1;
        }
        return true;
    }
    int smallestNumber(int n) {
        while(!helper(n)) {
            n++;
        }
        return n;
    }
};