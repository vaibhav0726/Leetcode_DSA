class Solution {
public:
    int mySqrt(int x) {
        int s = 0, e = x;
        long ans = INT_MIN;
        
        while(s <= e){
            long mid = s + ((e-s)/2);
            long sqr = mid*mid;
            if(sqr <= x){
                ans = max(ans,mid);
                s = mid+1;
            }
            else
                e = mid-1;
        }
        return (int)(ans);
    }
};