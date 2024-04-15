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
    void fun(TreeNode* root,int sum,int *ts)
    {
        if(root==nullptr) return ;
        sum=sum*10+root->val;
        if(root->left==nullptr && root->right==nullptr) *ts+=sum;
        fun(root->left,sum,ts);
        fun(root->right,sum,ts);

    }
    int sumNumbers(TreeNode* root) {
        int sum=0,ts=0;
        fun(root,sum,&ts);
        return ts;
        
    }
};