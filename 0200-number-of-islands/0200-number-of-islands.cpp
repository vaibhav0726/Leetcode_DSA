class Solution {
private:
    void bfs(vector<vector<char>>& grid, vector<vector<int>>& vis, int row, int col){
        vis[row][col] = 1;
        queue<pair<int,int>> q;
        q.push({row, col});
        int n = grid.size();
        int m = grid[0].size();
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            // traverse through neighbours and mark them vis if its a land
            int r[] = {-1, 1, 0, 0};
            int c[] = {0, 0, -1, 1};
            for(int i=0; i<4; i++){
                int nrow = row + r[i];
                int ncol = col + c[i];
                if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && grid[nrow][ncol] == '1' && vis[nrow][ncol] == 0){
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for(int row = 0; row < n; row++){
            for(int col = 0; col < m; col++){
                if(vis[row][col] == 0 && grid[row][col] == '1'){
                    count++;
                    bfs(grid, vis, row, col);
                }
            }
        } 
        return count;
    }
};