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
    vector<int> largestValues(TreeNode* root) {
        if(root == nullptr) return {};
        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);
        while(! q.empty()) {
            int n = q.size();
            int max_val = INT_MIN;
            for(int i = 0;i < n;i++) {
                TreeNode* a = q.front();
                if(a->left) q.push(a->left);
                if(a->right) q.push(a->right);
                max_val = max(max_val,a->val);
                q.pop();
            }
            ans.emplace_back(max_val);
        }

        return ans;
    }
};