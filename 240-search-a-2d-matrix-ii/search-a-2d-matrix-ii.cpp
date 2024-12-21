class Solution {
public:
    bool searchMatrix(vector<vector<int>>& arr, int target) {

       for (const auto& v : arr) {
        if(binary_search(v.begin(),v.end(), target)) return true;
       }
       return false;

    }
};