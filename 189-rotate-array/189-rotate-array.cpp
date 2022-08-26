class Solution {
private: 
    void reverse(vector<int>& nums,int a, int b, int n){
        // int n = b-1;
        for(int i=a; i<b; i++){
            int temp = nums[i];
            nums[i] = nums[n];
            nums[n] = temp;
            n--;
        }
    }
public:
    void rotate(vector<int>& nums, int k) {
        k = k%nums.size();
        reverse(nums, 0, nums.size()/2, nums.size()-1);
        reverse(nums, 0, k/2, k-1);
        reverse(nums, k, (nums.size()+k)/2, nums.size()-1);
        // reverse(nums,0, nums.size());
    }
};