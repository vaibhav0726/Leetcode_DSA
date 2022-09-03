class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int n = nums.size();
        int m = 0;
        for(int i=0; i<n; i++){
            if(nums[i] == 1){
                count++;
            }
            else{
                m = max(m, count);
                count=0;
            }
        }
        m= max(m, count);
        return m;
    }
};