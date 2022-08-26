class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return 0;
        long long int reverse = 0;
        long long int temp = x;
        while(temp!=0){
            reverse = reverse*10 + temp%10;
            temp/=10;
        }
        return reverse == x? true: false;
    }
};