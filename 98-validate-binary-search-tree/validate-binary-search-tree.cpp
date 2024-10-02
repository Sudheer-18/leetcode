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
    bool check_BST(TreeNode* root, TreeNode* min_nod, TreeNode* max_nod) {
        if (root == nullptr) return true;
        if (min_nod != nullptr && root->val <= min_nod->val) return false;
        if (max_nod != nullptr && root->val >= max_nod->val) return false;
        return check_BST(root->left, min_nod, root) && check_BST(root->right, root, max_nod);
    }

    bool isValidBST(TreeNode* root) {
        return check_BST(root,nullptr,nullptr);
    }
};
