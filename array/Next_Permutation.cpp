// A permutation of an array of integers is an arrangement of its members into a sequence or linear order.

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int idx1 = -1;
        int idx2 = -1, n = nums.size();
        
        for(int i=n-2; i>=0 ; i--){
            if(nums[i] < nums[i+1] ){
                idx1 = i;
                break;
            }
        }
        if(idx1 == -1){
            reverse(nums.begin(), nums.end());
            return;
        }
        
        for(int i=n-1; i>=0; i--){
            if(nums[i] > nums[idx1]){
                idx2 = i;
                break;
            }
        }
        
        swap(nums[idx1], nums[idx2]);
        idx1 += 1;
        reverse(nums.begin() + idx1, nums.end());
        return;
    }
    
};
