class Solution {
private:
    void setZeroesTwo(vector<vector<int>>& matrix, int n, int a, int b){
        for(int i = 0; i < matrix.size(); i++){
            matrix[i][b] = 0;
        }
        for(int i = 0; i < matrix[0].size(); i++){
            matrix[a][i] = 0;
        }
    }
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool col0 = true;
        int row = matrix.size(), col = matrix[0].size();
        for(int i = 0; i<row; i++){
            if(matrix[i][0] == 0) col0 = false;
            for(int j=1; j<col; j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }
        for(int i = row-1; i>=0; i--){
            for(int j = col-1; j>=1; j--){
                if(matrix[i][0] ==0 || matrix[0][j] == 0 ){
                    matrix[i][j] = 0;
                }
            }
            if(col0 == 0) matrix[i][0] = 0;
        }
        
        
    }
};