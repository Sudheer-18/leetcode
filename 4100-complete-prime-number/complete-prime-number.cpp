
class Solution {
    set<int> s = {2, 3, 5, 7, 23, 37, 53, 73, 313, 317, 373, 797, 3137, 3797, 739397};
public:
    bool completePrime(int num) {
        return s.count(num);
    }
};