class Solution {
public:
    int reversedigit(int n) {
        int r , s = 0;
        while(n != 0) {
            r = n % 10;
            s = s * 10 + r;
            n = n / 10;
        }
        return s;
    }
    int mirrorDistance(int n) {
        return abs(n - reversedigit(n));
    }
};