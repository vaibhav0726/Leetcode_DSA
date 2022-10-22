class Solution {
private:
    bool HasPath(vector<vector<char>>& board, string word, int cc, int cr, int idx){
        
        if(idx == word.size()){
            return true;
        }
        
        if(cc<0 || cr<0 || cc >= board[0].size() || cr >= board.size() || board[cr][cc] != word[idx]){
            return false;
        }
        
        int r[] = {-1, 1, 0, 0};
        int c[] = {0, 0, -1, 1};
        board[cr][cc] = '@';
        
        for(int i=0; i<4; i++){
            bool ans = HasPath(board, word, cc+c[i], cr+r[i], idx+1);
            if(ans == true) return ans;
        }
        
        board[cr][cc] = word[idx];
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if(board[i][j] == word[0]){
                    bool ans = HasPath(board, word, j, i, 0);
                    if(ans) return true;
                }
            }
        }
        return false;
    }
};