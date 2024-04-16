class Solution {
public:
    void recursion(TreeNode* root, int val, int depth, int current_depth) {
        if(root == nullptr) return;
        if(current_depth == depth - 1) {
            TreeNode* left_subtree = new TreeNode(val);
            TreeNode* right_subtree = new TreeNode(val);
            left_subtree->left = root->left;
            right_subtree->right = root->right;
            root->left = left_subtree;
            root->right = right_subtree;
            return;
        } 
        recursion(root->left, val, depth, current_depth + 1);
        recursion(root->right, val, depth, current_depth + 1);
    }
    
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(root == nullptr) return nullptr;
        if(depth == 1) {
            TreeNode* new_root = new TreeNode(val);
            new_root->left = root;
            return new_root;
        }
        recursion(root, val, depth, 1);
        return root;
    }
};
