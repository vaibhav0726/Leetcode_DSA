class Solution {
private:
//     tq = total queen
    void printPath(vector<vector<string>> &ans, vector<string> &nQueens, int row, int n){
        
        if(row == n){
            ans.push_back(nQueens);
            return;
        }
        
        for(int col=0; col < n; col++){
            if(isitPossible(nQueens, row, col, n)){
                nQueens[row][col] = 'Q';
                printPath(ans, nQueens, row+1, n);
                nQueens[row][col] = '.';
            }
        }
        return;
    }
    
    bool isitPossible(vector<string> &nQueens, int row, int col, int n){
        int r = row;
        int c = col;
//         uper jana hai
        
        while(r >= 0){
            if(nQueens[r][c] == 'Q')
                return false;
            r--;
        }
        
        // left diagonal
        r = row;
        c = col;
        while(r >=0 && c>=0){
            if(nQueens[r][c] == 'Q')
                return false;
            r--;
            c--;
        }
        
        // right diagonal
        r = row;
        c = col;
        while(r >=0 && c<n){
            if(nQueens[r][c] == 'Q')
                return false;
            r--;
            c++;
        }
        
        return true;
        
    }
public:
    int totalNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> nQueens(n, string(n, '.'));
        printPath(ans, nQueens, 0, n);
        return ans.size();
    }
};