class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int si = 0, en = 0;
        int ans = 0;
        int m = INT_MIN, p=1;
        while(en<n){
            p*=nums[en];
            
//             window shrink kro
            while(p>=k && si<=en){
                p = p/nums[si];
                si++;
            }
            ans = ans + en - si + 1;
            en++;
        }
        return ans;
        
    }
};