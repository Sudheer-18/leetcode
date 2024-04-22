class Solution {
public:
    bool isSameAfterReversals(int num) {
        if(num<10){
            return true;
        }
        int fake = num;
        if(fake%10==0){
            return false;
        }
        
        return true;
    }
};