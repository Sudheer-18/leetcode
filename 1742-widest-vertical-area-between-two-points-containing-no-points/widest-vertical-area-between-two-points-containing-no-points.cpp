class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        int n=points.size();
        sort(points.begin(),points.end());
        int mp=0,mc=0;
        for(int i=1;i<n;i++) {
            mc=points[i][0]-points[i-1][0];
            mp=max(mp,mc);
        }
        return mp;
        
    }
};