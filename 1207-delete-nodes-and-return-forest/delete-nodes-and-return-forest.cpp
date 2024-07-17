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
    TreeNode* dfs(TreeNode* root,unordered_set<int> & del,vector<TreeNode*>& ans) {
        if(root == nullptr) return nullptr;
        root->left = dfs(root->left,del,ans);
        root->right = dfs(root->right,del,ans);
        if(del.find(root->val) != del.end()) {
            if(root->left != nullptr) ans.push_back(root->left);
            if(root->right != nullptr) ans.push_back(root->right);
            return nullptr;
        }
        return root;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        int n = to_delete.size();
        if(root == nullptr) return {nullptr};
        if(n == 0) return {root};
        vector<TreeNode*>ans;
        unordered_set<int> to_del;
        for(auto ar : to_delete) {
            to_del.insert(ar);
        }
         dfs(root,to_del,ans);
         if(to_del.find(root->val) == to_del.end()) {
            ans.push_back(root);
         }
         return ans;
    }
};