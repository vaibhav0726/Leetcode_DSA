class Solution {
    int solve(string &s)
    {
        int i = 0;
        int n = s.size();
        // step 1 ignoring whitespaces
        while(i < n && s[i] == ' ')
            i++;
        
        // step 2 checking sign
        char sign = '+';
        if(i < n && (s[i] == '+' || s[i] == '-'))
            sign = s[i++];
        
        // step 3 number formation
        long num = 0; // long to detect number "-2147483649" or "2147483649"
        if(sign == '-')
        {
            // for negative number
            while(i < n && s[i] >= '0' && s[i] <= '9')
            {
                if(num < INT_MIN/10)
                {
                    return INT_MIN;
                }
                
                num = num*10 - (s[i] - '0');
                i++;
            }
        }
        else{
            // for positive number
            while(i < n && s[i] >= '0' && s[i] <= '9')
            {
                if(num > INT_MAX/10)
                {
                    return INT_MAX;
                }
                
                num = num*10 + (s[i]-'0');
                i++;
            }
        }
        // if num is "2147483649" or "2147483648"
        if(num > INT_MAX)
            num = INT_MAX;
        else if(num < INT_MIN) // if num is "-2147483649"
            num = INT_MIN;
        
        return num;
    }
public:
    int myAtoi(string s) {
        return solve(s);
    }
};