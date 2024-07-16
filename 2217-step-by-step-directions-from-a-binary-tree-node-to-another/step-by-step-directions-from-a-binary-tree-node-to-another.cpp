class Solution {
public:
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