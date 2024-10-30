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
    int max_val = INT_MIN;
    int helper(TreeNode* root) {
        if(root == nullptr) return 0;
        int left = helper(root->left);
        int right = helper(root->right);
        max_val = max(max_val,left+right+root->val);
        max_val = max(max_val,left+root->val);
        max_val = max(max_val,right+root->val);
        max_val = max(max_val,root->val);
        return max(root->val,root->val+max(left,right));
    }
    int maxPathSum(TreeNode* root) {
        max_val = INT_MIN;
        helper(root);
        return max_val;
    }
};