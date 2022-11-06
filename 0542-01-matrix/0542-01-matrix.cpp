class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int, int>> q;
        for(int i=0; i<mat.size(); i++){
            for(int j=0; j<mat[0].size(); j++){
                if(mat[i][j] == 0){
                    q.push({i, j});
                }
                else{
                    mat[i][j] = -1;
                }
            }
        }
        
        int r[] = {1, -1, 0, 0};
        int c[] = {0, 0, -1, 1};
        while(q.size() > 0){
            pair<int, int> fron = q.front();
            q.pop();
            for(int i=0; i<4; i++){
                int nrow = fron.first + r[i];
                int ncol = fron.second + c[i];
                if(nrow >=0 && ncol >=0 && nrow <mat.size() && ncol < mat[0].size() && mat[nrow][ncol] < 0){
                    q.push({nrow, ncol});
                    mat[nrow][ncol] = mat[fron.first][fron.second] + 1;
                }
            }
        }
        return mat;
    }
};