class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
//         {{row, col}, time}
        queue<pair<pair<int, int>, int>> q;
        // vector<vector<int>> vis(n, vector<int>(m, 0));
        int vis[n][m];
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 2){
                    q.push({ {i, j}, 0} );
                    vis[i][j] = 2;
                }
                else{
                    vis[i][j] = 0;
                }
            }
        }
        int t = 0;
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int time = q.front().second;
            q.pop();
            t = max(t, time);
            int r[] = {1, -1, 0, 0};
            int c[] = {0, 0, -1, 1};
            for(int i=0; i<4; i++){
                int nrow = row + r[i];
                int ncol = col + c[i];
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1){
                    q.push({{nrow, ncol}, time+1});
                    vis[nrow][ncol] = 2;
                }
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(vis[i][j] !=2 && grid[i][j] == 1){
                    return -1;
                }
            }
        }
        return t;
        
    }
};