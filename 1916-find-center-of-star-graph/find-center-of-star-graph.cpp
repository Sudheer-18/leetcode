class Solution {
public:
    int findCenter(vector<vector<int>>& arr) {
       if(arr[0][0]==arr[1][0]) return arr[0][0];
       else if(arr[0][0] == arr[1][1]) return arr[0][0];
     return arr[0][1];   
    }
};