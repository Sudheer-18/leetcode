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
    vector<long long> arr;
    void bfs(TreeNode* root) {
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()) {
            int n = q.size();
            vector<int> vec;
            for(int i=0;i<n;i++) {
                TreeNode* tmp = q.front();
                q.pop();
                if(tmp->left != nullptr) q.push(tmp->left);
                if(tmp->right != nullptr) q.push(tmp->right);
                vec.push_back(tmp->val);
            }
           long long sum = 0;
           for(int ele : vec) {
            sum+=ele;
           }
           arr.push_back(sum);
            vec.clear(); 
        }
    }
    long long kthLargestLevelSum(TreeNode* root, int k) {
        bfs(root);
        if(k > arr.size()) return -1;
       sort(arr.begin(),arr.end());
       for(auto ele : arr) cout<<ele<<" ";
       cout<<endl;
       long long n = arr.size();
       return arr[n-k];
    }
};