class Solution {
public:
    bool isPowerOfTwo(int n) {
        int p= 0;
        while(1) {
            if(pow(2,p) == n) return true;
            if(pow(2,p) > n) return false;
            p++;    
        }
        return false;
    }
};