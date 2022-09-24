class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int low = 0, high = m*n;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(isLessThanK(mid, m, n) >= k){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return low;
    }
    
    int isLessThanK(int element, int m, int n){
        int sum = 0; 
        for(int i=1; i<=m; i++){    
            sum+=min(element/i, n);
        }
        return sum;
    }
};