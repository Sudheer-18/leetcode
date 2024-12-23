/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans = 0;
    
    void helper(vector<int> &arr) {

        int n = arr.size();
        vector<pair<int, int>> arrPos(n);
        
        for (int i = 0; i < n; i++) {
            arrPos[i] = {arr[i], i};
        }

        sort(arrPos.begin(), arrPos.end());
        vector<bool> visited(n, false);
        int swaps = 0;

        for (int i = 0; i < n; i++) {
            if (visited[i] || arrPos[i].second == i) continue;

            int cycleSize = 0;
            int j = i;

            while (!visited[j]) {
                visited[j] = true;
                j = arrPos[j].second;
                cycleSize++;
            }

            if (cycleSize > 1) swaps += (cycleSize - 1);
        }

        ans += swaps;
}

    int minimumOperations(TreeNode* root) {

        queue<TreeNode *> q;
        q.push(root);
        while(! q.empty()) {
            int n = q.size();
            vector<int> v;
            for(int i = 0; i < n; i++) {
                TreeNode* a = q.front();
                if(a->left) q.push(a->left);
                if(a->right) q.push(a->right);
                q.pop();
                v.emplace_back(a->val);
            }
            helper(v);
            v.clear();
        }

        return ans;
        
    }
};