class Solution {
public:
    double myPow(double x, int n) {
        double res = 1;
        long long nn = n;
        if(n < 0) nn = nn*-1;
        while(nn){
            if(nn%2){
                res = res * x;
                nn = nn-1;                
            }
            else{
                x = x * x;
                nn = nn / 2;
            }
        }
       if(n < 0)
           return (double)(1)/res;
       else 
           return res; 
    }
};