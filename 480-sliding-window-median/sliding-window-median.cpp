class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<double> res;
        multiset<long long> ms1,ms2;
        auto check_balance = [&]() {
            if (ms1.size() > ms2.size() + 1) {
                ms2.insert(*ms1.rbegin());
                ms1.erase(prev(ms1.end())); 
            }
            if (ms1.size() < ms2.size()) {
                ms1.insert(*ms2.begin());
                ms2.erase(ms2.begin());
            }
        };
        for(int i = 0; i < n; i++) {
            if(ms1.empty() or nums[i] <= *ms1.rbegin()) ms1.insert(nums[i]);
            else ms2.insert(nums[i]);
            check_balance();
            if(i >= k) {
                long long val  = nums[i - k];
                auto it = ms1.find(val);
                if(it != ms1.end()) {
                    ms1.erase(it);
                }
                else {
                     it = ms2.find(val);
                    if(it != ms2.end()) {
                        ms2.erase(it);
                    }
                }
                check_balance();
            }
            if(i >= k - 1) {
                if(k % 2 == 1) {
                    res.push_back(*ms1.rbegin());
                }
                else {
                     res.push_back(((double)*ms1.rbegin() + (double)*ms2.begin()) / 2.0);
                }
            } 
        }
        return res;
    }

};