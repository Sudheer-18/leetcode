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
    void cnt_Nodes(TreeNode* root, int &cnt) {
        if(root == nullptr) return ;
        cnt++;
        cnt_Nodes(root->left, cnt);
        cnt_Nodes(root->right, cnt);
    }
    
    int countNodes(TreeNode* root) {
        int cnt = 0;
        if(root == nullptr) return cnt;
        cnt_Nodes(root, cnt);
        return cnt;
    }
};
