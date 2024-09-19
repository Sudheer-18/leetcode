class Solution {
public:
    int helper(int x,int y,char ch) {
        if(ch == '+') return x+y;
        if(ch == '-') return x-y;
        if(ch == '*') return x*y;
        return 0;
    }
    vector<int> diffWaysToCompute(string expression) {
        vector<int> ans;
        bool is_num = true;
        for(int i=0;i<expression.length();i++) {
            if(!isdigit(expression[i])) {
                is_num = false;
                vector<int> l = diffWaysToCompute(expression.substr(0,i));
                vector<int> r = diffWaysToCompute(expression.substr(i+1));
                for(int a : l) {
                    for(int b : r) {
                        int val  = helper(a,b,expression[i]);
                        ans.push_back(val);
                    }
                }
            }

        }
        if(is_num) ans.push_back(stoi(expression));
        return ans;
    }
};