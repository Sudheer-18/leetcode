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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == nullptr) return {};
        if(root->left == nullptr && root->right == nullptr) return {{root->val}};
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        int val = 0;
        while(!q.empty()) {
            int n = q.size();
            vector<int> v;
            for(int i = 0; i < n; i++) {
                TreeNode* tmp = q.front();
                if(tmp->left != nullptr) q.push(tmp->left);
                if(tmp->right != nullptr) q.push(tmp->right);
                v.push_back(tmp->val);
                q.pop();
            }
            if(val % 2 != 0) {
                reverse(begin(v),end(v));
            }
            ans.push_back(v);
            val++;
        }

        return ans;
    }
};