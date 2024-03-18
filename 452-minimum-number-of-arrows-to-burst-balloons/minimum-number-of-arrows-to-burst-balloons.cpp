class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int position = points[0][1];
        int count = 1;
        for(int i = 1; i<points.size(); i++){
            if(position>=points[i][0])
                position = min(position, points[i][1]);
            else{
                count++;
                position = points[i][1];
            }
        }
        return count;
    }
};