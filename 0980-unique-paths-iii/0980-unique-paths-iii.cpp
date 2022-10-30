class Solution {
private:
    void solve(vector<vector<int>>& grid, int row, int col, int &count, int zeros){
        if(row<0 || col<0 || row>=grid.size() || col>=grid[0].size() || grid[row][col] == -1){
            return;
        }
        if(grid[row][col]==2 && zeros == 0){
            count++;
            return;
        }
        int r[] = {1, -1, 0, 0};
        int c[] = {0, 0, -1, 1};
        for(int i=0; i<4; i++){
            if(grid[row][col] == 0){
                grid[row][col] = -1;
                solve(grid, row+r[i], col+c[i], count, zeros-1);
                grid[row][col] = 0;
            }
        }
    }
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int count = 0;
        int zeros =0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == 0){
                    zeros++;
                }
            }
        }
        cout<<zeros;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == 1){
                    grid[i][j] = 0;
                    solve(grid, i, j, count, zeros+1);
                    return count;
                }
            }
        }
        return count;
    }
};