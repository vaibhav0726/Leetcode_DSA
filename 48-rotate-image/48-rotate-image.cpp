class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for(int i=0; i<matrix.size(); i++)
        {
            for(int j=i; j<matrix[i].size(); j++)
            {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
        
        for(int i=0; i<matrix.size(); i++)
        {
            for(int j=0; j<matrix[i].size()/2; j++)
            {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[i][matrix[i].size()-1-j];
                matrix[i][matrix[i].size()-1-j] = temp;
            }
        }
    }
};