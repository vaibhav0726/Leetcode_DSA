class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        int n = s.size();
        char v[numRows][n];
        int rows = sizeof(v)/sizeof(v[0]);
        int cols = sizeof(v[0])/sizeof(v[0][0]);
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                v[i][j] = ' ';
            }
        }
        int j = 0;
        string res="";
        int i=0;
        while(j<n){
            for(int x=0; x<numRows && j<n; x++){
                v[x][i]=s[j];  
                j++;
            }
            i++;
            for(int y=numRows-2; y>0 && j<n; y--){
                v[y][i]=s[j];
                j++;
                i++;
            }
        }
        
        for(i=0; i<rows; i++){
            for(j=0; j<cols; j++){
                if(v[i][j]!=' ')
                    res+=v[i][j];
            }
        }
        return res;
    }
};