class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long pre_sum = 0;
        int n = chalk.size();
        for(int i = 0; i < n; i++) {
            pre_sum += chalk[i];
        }
        if(pre_sum > k) {
            pre_sum = 0;
            for(int i = 0; i < n; i++) {
                pre_sum += chalk[i];
                if(pre_sum > k) return i;
            }
        } else {
            k %= pre_sum;
            pre_sum = 0;
            for(int i = 0; i < n; i++) {
                pre_sum += chalk[i];
                if(pre_sum > k) return i;
            }
        }
        return 0;
    }
};
