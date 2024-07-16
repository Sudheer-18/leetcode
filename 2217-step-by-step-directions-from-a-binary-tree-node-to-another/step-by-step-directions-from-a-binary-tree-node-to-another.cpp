class Solution {
public:
    vector<vector<int>> bfs_call(TreeNode* root, unordered_map<int, TreeNode*>& parentMap) {
        vector<vector<int>> ans;
        if (!root) return ans;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            vector<int> arr;
            int n = q.size();
            
            for (int i = 0; i < n; i++) {
                TreeNode* ele = q.front();
                q.pop();
                
                if (ele->left != nullptr) {
                    q.push(ele->left);
                    parentMap[ele->left->val] = ele;
                }
                if (ele->right != nullptr) {
                    q.push(ele->right);
                    parentMap[ele->right->val] = ele;
                }
                
                arr.push_back(ele->val);
            }
            ans.push_back(arr);
        }
        
        return ans;
    }

    bool findPath(TreeNode* root, int value, string& path) {
        if (!root) return false;
        if (root->val == value) return true;
        
        if (root->left && findPath(root->left, value, path)) {
            path.push_back('L');
            return true;
        }
        if (root->right && findPath(root->right, value, path)) {
            path.push_back('R');
            return true;
        }
        
        return false;
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {
        unordered_map<int, TreeNode*> parentMap;
        bfs_call(root, parentMap);
        
        string startPath, destPath;
        findPath(root, startValue, startPath);
        findPath(root, destValue, destPath);
        
        reverse(startPath.begin(), startPath.end());
        reverse(destPath.begin(), destPath.end());
        
        int i = 0;
        while (i < startPath.size() && i < destPath.size() && startPath[i] == destPath[i]) {
            i++;
        }
        
        string directions;
        for (int j = i; j < startPath.size(); j++) {
            directions.push_back('U');
        }
        for (int j = i; j < destPath.size(); j++) {
            directions.push_back(destPath[j]);
        }
        
        return directions;
    }
};