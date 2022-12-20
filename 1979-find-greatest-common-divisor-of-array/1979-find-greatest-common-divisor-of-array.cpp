class Solution {
public:
    int gcd(int a, int b)
    {
        int result = min(a, b);
        while (result > 0) {
            if (a % result == 0 && b % result == 0) {
                break;
            }
            result--;
        }
        return result;
    }
    int findGCD(vector<int>& nums) {
        int mi = INT_MAX, ma = INT_MIN;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] < mi){
                mi = nums[i];
            }
            if(nums[i] > ma){
                ma = nums[i];
            }
        }
        return gcd(mi, ma);
    }
};