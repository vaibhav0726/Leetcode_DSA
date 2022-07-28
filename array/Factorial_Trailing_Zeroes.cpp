//mine simple approach 
class Solution {
public:
    int trailingZeroes(int n) {
        int res = 0;
        for(int i=5;i<=n; i=i*5){
            res = res + n/i;
        }
        return res;
    }
};

// single line same approach:-
return n == 0 ? 0 : n / 5 + trailingZeroes(n / 5);
