class Solution {
public:
    int trap(vector<int>& height) {
        // simple approach:-
        int n = height.size();
        int left[n];
        left[0] = height[0];
        int water= 0;
        for(int i=1; i<n; i++){
            left[i] = max(left[i-1], height[i]); 
        }
        int right[n];
        right[n-1] = height[n-1];
        for(int i=n-2; i>=0; i--){
            right[i] = max(right[i+1], height[i]); 
        }
        for(int i=0; i<n; i++){
            water+=min(left[i],right[i]) - height[i];
        }
        return water;
        
        
        // Efficient Approach
        // int n = height.size();
        // int leftMax = 0, rightMax = 0;
        // int left = 0, right = n-1;
        // int water = 0;
        // while(left<right){
        //     if(height[left] < height[right]){
        //         if(height[left] > leftMax){
        //             leftMax = height[left];
        //         }
        //         else{
        //             water+= leftMax-height[left];
        //         }
        //         left++;
        //         continue;
        //     }
        //     else{
        //         if(height[right] > rightMax){
        //             rightMax = height[right];
        //         }
        //         else{
        //             water+= rightMax-height[right];
        //         }
        //         right--;
        //         continue;
        //     }
        // }
        // return water;
    }
};