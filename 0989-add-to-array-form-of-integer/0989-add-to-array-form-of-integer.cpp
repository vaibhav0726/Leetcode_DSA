class Solution {
public:
    vector<int> addToArrayForm(vector<int>& nums, int k) {
        int carry = 0;
        for(int i=nums.size() -1; i>=0; i--){
            int res = nums[i] + k%10 + carry;
            carry = 0;
            if(res > 9){
                nums[i] = res %10;
                carry = 1;
            }
            else{
                nums[i] = res;
            }
            k = k/10;
        }
        while(k){
            int res = k % 10 + carry;
            nums.insert(nums.begin(), res%10);
            carry = 0;
            if(res > 9) carry = 1;
            k = k / 10;
        }
        if(carry){
            nums.insert(nums.begin(), 1);
        }
        return nums;
    }
};