class Solution {
public:
    bool isThree(int n) {
        if(n==1 or n==2)
        {
            return false;
        }
        int a=sqrt(n);
    
        if(a*a==n)
        {
            for(int i=2;i<a;i++)
            {
                
            
                if(n%i==0)
                {
                    return false;
                }
            }
            return true;
        }
        return false;
    }
};