class Solution {
public:
    bool isvalid(int x, vector<int> &ds, int k) {
        for (int i = 0; i < ds.size(); i++) {
            if (abs(ds[i] - x) == k) return false;
        }
        return true;
}

void solve(int ind, vector<int> &ds, vector<int> &nums, int &ans, int n, int k) {
    if (ind == n) {
        ans++;
        return;
    }
    if (isvalid(nums[ind], ds, k)) {
        ds.push_back(nums[ind]);
        solve(ind + 1, ds, nums, ans, n, k);
        ds.pop_back();   
    }
    solve(ind + 1, ds, nums, ans, n, k);
}

int beautifulSubsets(vector<int> &nums, int k) {
    int n = nums.size();
    vector<int> ds;
    int ans = 0;
    solve(0, ds, nums, ans, n, k);
    return ans - 1;
    }
};