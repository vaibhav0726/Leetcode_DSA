class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int x1 = coordinates[0][0], y1 = coordinates[0][1];
        int yDifference = y1 - coordinates[1][1];
        int xDifference = x1 - coordinates[1][0];
        for(int i = 2; i<coordinates.size(); i++){
            if(yDifference * (coordinates[i][0]-x1) != xDifference * (coordinates[i][1]-y1)){
                return false;
            }
        }
        
        return true;
    }
};