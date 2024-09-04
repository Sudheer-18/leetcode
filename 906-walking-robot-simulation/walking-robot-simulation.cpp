class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        set<pair<int, int>> obstacleSet;
        for (auto obs : obstacles) {
            obstacleSet.insert({obs[0], obs[1]});
        }
        int x = 0, y = 0; 
        int directionIndex = 0; 
        int maxDist = 0;
        for (int cmd : commands) {
            if (cmd == -2) {
                directionIndex = (directionIndex + 3) % 4;
            } 
            else if (cmd == -1) {
                directionIndex = (directionIndex + 1) % 4;
            } 
            else {
                for (int i = 0; i < cmd; ++i) {
                    int newX = x + directions[directionIndex].first;
                    int newY = y + directions[directionIndex].second;
                    if (obstacleSet.find({newX, newY}) == obstacleSet.end()) {
                        x = newX;
                        y = newY;
                        maxDist = max(maxDist, x * x + y * y);
                    } 
                }
            }
        }
        
        return maxDist;
    }
};
