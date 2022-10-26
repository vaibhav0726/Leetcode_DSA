class Solution {
private:
    bool isitPossible(vector<vector<char>>& board, int row, int col, char val){
        for(int i=0; i<9; i++){
            if(board[i][col] == val) return false;
            if(board[row][i] == val) return false;
        }
        
        int r = row - row%3;
        int c = col - col%3;
        for(int i=r; i<r+3; i++){
            for(int j=c; j<c+3; j++){
                if(board[i][j] == val)
                    return false;
            }
        }
        return true;
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    char c=board[i][j];
                    board[i][j]='.';
                    if(!isitPossible(board,i,j,c))return false;
                    board[i][j]=c;
                }
            }
        }
        return true;
    }
};