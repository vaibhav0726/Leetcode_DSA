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
                // if(v[i][j]>='A' && v[i][j]<='Z'){
                //     res+=v[i][j];
                // }
                v[i][j] = ' ';
            }
        }
        int j = 0;
        string res="";
        int i=0;
        while(j<n){
            for(int x=0; x<numRows && j<n; x++)
            {
                v[x][i]=s[j];
                // cout<<x<<" "<<i<<" "<<j<<" "<<v[x][i]<<" "<<endl;   
                j++;
            }
            i++;
            for(int y=numRows-2; y>0 && j<n; y--)
            {
                v[y][i]=s[j];
                 // cout<<y<<" "<<i<<" "<<j<<" "<<v[y][i]<<" "<<endl;
                j++;
                i++;
            }
            // i++;
        }
        
        // cout<<rows<<cols;
        for(i=0; i<rows; i++){
            for(j=0; j<cols; j++){
                // if((v[i][j]>='A' && v[i][j]<='Z') || ((v[i][j]>='a' && v[i][j]<='z'))){
                //     res+=v[i][j];
                //     cout<<v[i][j];
                // }
                if(v[i][j]!=' ')
                    res+=v[i][j];
                
            }
            // cout<<endl;
        }
        cout<<"res"<<res<<endl;
        return res;
    }
};