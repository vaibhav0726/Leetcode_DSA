class Solution {
private:
    void dfs(vector<vector<int>>& image, vector<vector<int>>& ans, int row, int col, int newColor, int iniColor){
        ans[row][col] = newColor;
        int r[] = {-1, 1, 0, 0};
        int c[] = {0, 0, -1, 1};
        int n = image.size();
        int m = image[0].size();
        for(int i=0; i<4; i++){
            int nrow = row + r[i];
            int ncol = col + c[i];
            if(nrow >=0 && ncol>=0 && nrow<n && ncol<m && image[nrow][ncol] == iniColor && ans[nrow][ncol] != newColor){
                dfs(image, ans, nrow, ncol, newColor, iniColor);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int iniColor = image[sr][sc];
        vector<vector<int>> ans = image;
        dfs(image, ans, sr, sc, color, iniColor);
        return ans;
    }
};