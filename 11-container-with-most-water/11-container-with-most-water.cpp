class Solution {
public:
    int maxArea(vector<int>& height) {
        // int left = 0, right = height.size()-1;
        // int res = 0;
        // while(left < right){
        //     int area = min(height[left], height[right]) * (right - left);
        //     res = max(res, area);
        //     if(height[left] < height[right] ){
        //         left++;
        //     }
        //     else{
        //         right--;
        //     }
        // }
        // return res;
        
        
//         Efficient solution
        int water = 0;
    int i = 0, j = height.size() - 1;
    while (i < j) {
        int h = min(height[i], height[j]);
        water = max(water, (j - i) * h);
        while (height[i] <= h && i < j) i++;
        while (height[j] <= h && i < j) j--;
    }
    return water;
    }
};