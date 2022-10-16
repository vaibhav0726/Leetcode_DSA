class Solution {
public:
    int concatenatedBinary(int n) {
        long long int ans = 0;
        if(n == 1) return n;
        for(int i=1; i<=n; i++){
            ans = ((ans << (1 + int(log2(i)))) % 1000000007  + i ) % 1000000007;
        }
        return ans;
    }
};