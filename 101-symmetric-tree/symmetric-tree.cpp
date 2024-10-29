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
    bool helper(TreeNode* nrml_pointer,TreeNode* mrror_pointer) {
        if(nrml_pointer == nullptr  && mrror_pointer == nullptr) return true;
        if(nrml_pointer == nullptr || mrror_pointer == nullptr) return false;
        if(nrml_pointer->val != mrror_pointer->val) return false;
        bool left = helper(nrml_pointer->left,mrror_pointer->right);
        bool right = helper(nrml_pointer->right,mrror_pointer->left);
        return left && right;
    }
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr) return true;
        TreeNode* nrml_pointer = root->left;
        TreeNode* mrror_pointer = root->right;
        return helper(nrml_pointer,mrror_pointer);
    }
};