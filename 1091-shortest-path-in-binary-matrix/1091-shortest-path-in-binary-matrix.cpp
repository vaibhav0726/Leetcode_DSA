class Solution {
public:
    // Helper function to check if point is in grid
    bool isValidPoint(int x, int y, int n) {
        return x >= 0 && x < n && y >= 0 && y < n;
    }
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] || grid[n-1][n-1]) 
            return -1;
        
        queue<vector<int>> q;
        
        q.push({0, 0, 1});
        grid[0][0] = 1;
        
        while (!q.empty()) {
            int si = q.size();
            while(si--){
                // cout << "hello" << endl;
                vector<int> curr = q.front();
                q.pop();

                if(curr[0] == n-1 && curr[1] == n-1){
                    return curr[2];
                }

                for (int i = 0; i < 8; i++) {
                    int r = curr[0] + x_points[i];
                    int c = curr[1] + y_points[i];
                        // cout << r << " " << c << endl;

                    if (isValidPoint(r, c, n) && grid[r][c] == 0) {
                        // cout << r << " " << c << endl;
                        grid[r][c] = 1;
                        q.push({r, c, curr[2] + 1});
                    }
                }
            }
        }
        return -1;
    }
    
private:
    vector<int> x_points = {-1,-1,-1,0,0,1,1,1};
    vector<int> y_points = {-1,0,1,-1,1,-1,0,1};
};
