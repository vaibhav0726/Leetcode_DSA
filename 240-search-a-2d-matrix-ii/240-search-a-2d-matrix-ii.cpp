class Solution {
public:
    bool searchMatrix(vector<vector<int>>& arr, int target) {
        // for(int i=0; i<matrix.size(); i++){
        //     for(int j=0; j<matrix[i].size(); j++){
        //         if(matrix[i][j]==target){
        //             return true;
        //         }
        //     }
        // }
        int i = 0;
        int j = arr[0].size() - 1;
        while(i<arr.size() && j>=0){
            if(arr[i][j] == target)
                return true;
            if(arr[i][j] < target){
                i++;
            }
            else{
                j--;
            }
        }
        return false;
    }
};