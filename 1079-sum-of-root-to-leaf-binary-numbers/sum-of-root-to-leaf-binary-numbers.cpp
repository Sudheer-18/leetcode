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
// class Solution {
    
// public:
//     int ans = 0;
//     int binary(string st) {
//         int k=0,m=0;
//         int n = st.size();
//         for(int i=n-1;i>=0;i--) {
//             m+=(st[i]-'0')*pow(2,k);
//             k++;
//         }
//         return m;
//     }
//     void dfs(TreeNode* root,string st) {
//         if(root == nullptr) return;
//         if(root->left == nullptr && root->right == nullptr) {
//             st+=to_string(root->val);
//             ans+=binary(st);
//             return ;
//         }
//         st+=to_string(root->val);
//         if(root->left!=nullptr) dfs(root->left,st);
//         if(root->right != nullptr) dfs(root->right,st);
//     }
//     int sumRootToLeaf(TreeNode* root) {
//        if(root == nullptr) return 0;
//        dfs(root,"");
//        return ans;

//     }
// };
class Solution {
public:
    int sumRootToLeaf(TreeNode* root, int val = 0) {
        if(root == NULL) return 0;
        val = val * 2 + root->val;
        return root->left == root->right ? val : sumRootToLeaf(root->left, val) + sumRootToLeaf(root->right, val);
    }
};