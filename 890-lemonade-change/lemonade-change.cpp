
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        queue<int> five, ten;
        for(int bill : bills) {
            if(bill == 5) {
                five.push(bill);
            } else if(bill == 10) {
                if(five.empty()) return false;
                five.pop();
                ten.push(bill);
            } else {
                if(!ten.empty() && !five.empty()) {
                    ten.pop();
                    five.pop();
                } else if(five.size() >= 3) {
                    five.pop();
                    five.pop();
                    five.pop();
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};
