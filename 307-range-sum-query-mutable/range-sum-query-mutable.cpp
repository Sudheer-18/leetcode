class NumArray {
public:
    int n;
    vector<int> Tree;
    NumArray(vector<int>& nums) {
        n = nums.size();
        Tree.resize(4*n);
        Build(0,0,n-1,nums);
    }
    void Build(int idx, int start, int end, vector<int>& nums) {
        if (start == end) {
            Tree[idx] = nums[start];
            return;
        }
        int mid = (start + end) / 2;
        Build(2*idx+1,start,mid,nums);
        Build(2*idx+2, mid+1,end,nums);
        Tree[idx] = Tree[2*idx+1] + Tree[2*idx+2];  
    }
    int Query(int idx, int s, int e, int Qs, int Qe) {
        if (Qs > e || Qe < s) return 0;  
        if (Qs <= s && Qe >= e) return Tree[idx];  
        int mid = (s + e) / 2;
        return Query(2*idx+1,s,mid,Qs,Qe) + Query(2*idx+2,mid + 1,e,Qs,Qe);
    }
    void ArrayUpdate(int idx, int s, int e, int index, int val) {
        if (s == e) {
            Tree[idx] = val;
            return;
        }
        int mid = (s + e) / 2;
        if (index <= mid) {
            ArrayUpdate(2 * idx + 1, s, mid, index, val);
        } else {
            ArrayUpdate(2 * idx + 2, mid + 1, e, index, val);
        }
        Tree[idx] = Tree[2 * idx + 1] + Tree[2 * idx + 2];  
    }
    void update(int index, int val) {
        ArrayUpdate(0, 0, n - 1, index, val);
    }
    int sumRange(int left, int right) {
        return Query(0, 0, n - 1, left, right);
    }
};
