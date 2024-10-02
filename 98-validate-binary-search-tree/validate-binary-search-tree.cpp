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
    bool isValidBST(TreeNode* root) {
        if (root == nullptr) return true;  
        queue<pair<TreeNode*, pair<long long, long long>>> q;
        q.push({root, {LLONG_MIN, LLONG_MAX}});
        while (!q.empty()) {
            TreeNode* node = q.front().first;
            long long lower = q.front().second.first;
            long long upper = q.front().second.second;
            q.pop();
            if (node->val <= lower || node->val >= upper) return false;
            if (node->left != nullptr) {
                q.push({node->left, {lower, node->val}});
            }
            if (node->right != nullptr) {
                q.push({node->right, {node->val, upper}});
            }
        }
        return true; 
    }
};
