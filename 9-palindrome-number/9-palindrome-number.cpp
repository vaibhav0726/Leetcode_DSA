class Solution {
public:
    bool isPalindrome(int x) {
        int n =x;
        int ans = 0;
        if(x<0)
            return false;
        while(n!=0){
            int rem = n%10;
            if(ans>INT_MAX/10)
                return false;
            ans = ans*10 + rem;
            n = n/10;            
        }
        // cout<<"ans"<<ans<<endl;
        if(x==ans)
            return true;
        else
            return false;
    }
};