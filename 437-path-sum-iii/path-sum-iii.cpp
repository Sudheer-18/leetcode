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
    int dfs(TreeNode* root, long long ts) {
        if (root == nullptr) return 0;
        int count = 0;
        if (ts == root->val) count++; 
        count += dfs(root->left, ts - root->val);
        count += dfs(root->right, ts - root->val);
        return count;
    }

    int pathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int Cnt = 0;
        while (!q.empty()) {
            TreeNode* a = q.front();
            q.pop();
            Cnt += dfs(a, targetSum);  
            if (a->left) q.push(a->left);
            if (a->right) q.push(a->right);
        }

        return Cnt;
    }
};
