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
    vector<vector<int>> ans;
    void DFS(TreeNode* root, int Ts, int Ps, vector<int>& V) {
        if (root == nullptr) return;
        V.push_back(root->val);
        Ps += root->val;
        if (root->left == nullptr && root->right == nullptr && Ps == Ts) {
            ans.push_back(V);
        }
        DFS(root->left, Ts, Ps, V);
        DFS(root->right, Ts, Ps, V);
        V.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        DFS(root, targetSum, 0, path);
        return ans;
    }
};
 