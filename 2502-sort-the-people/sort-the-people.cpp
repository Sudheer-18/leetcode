class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = heights.size();
        // Bubble sort implementation
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n - i - 1; j++) {
                if(heights[j] < heights[j + 1]) {  // Sort in descending order
                    // Swap heights
                    int tempHeight = heights[j];
                    heights[j] = heights[j + 1];
                    heights[j + 1] = tempHeight;
                    
                    // Swap names
                    string tempName = names[j];
                    names[j] = names[j + 1];
                    names[j + 1] = tempName;
                }
            }
        }   
        return names;     
    }
};
