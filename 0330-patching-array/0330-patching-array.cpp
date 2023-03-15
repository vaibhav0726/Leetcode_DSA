class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long int patches = 0, missing = 1;
        int i = 0;
        // if(nums[nums.size() - 1] >= n){
        //     return 0;
        // }
        // while(i<nums.size()){
        //     if(nums[i] < missing){
        //         patches++;
        //         missing = missing*2;
        //     }
        //     else{
        //         missing++;
        //         i++;
        //     }
        // }
        // while(missing <= n){
        //     patches++;
        //     missing = missing*2;
        // }
        while(missing <= n){
            if(i<nums.size() && missing >= nums[i]){
                missing += nums[i];
                i++;
            }
            else{
                patches++;
                missing += missing;
            }
        }
        return patches;
    }
};