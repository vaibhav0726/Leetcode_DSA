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
    
    bool solve(vector<vector<char>>& board, int row, int col){
        if(row==8 && col==9){
			return true;
		}
		if(col==9){
			col=0;
			row+=1;
		}
		if(board[row][col]!='.'){
			if(solve(board,row,col+1))return true;
		}
		else {
			for(int k=49;k<=57;k++){
                char ch = (char)k;
				if(isitPossible(board,row,col,ch)){
					board[row][col]=ch;
					if(solve(board,row,col+1))return true;
					board[row][col]='.';
				}
			}
		}	
        return false;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board, 0, 0);
    }
};