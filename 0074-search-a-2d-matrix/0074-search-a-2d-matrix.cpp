class Solution {
    bool search(vector<int> arr, int t){
        int low = 0, high = arr.size();
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(arr[mid] == t){
                return true;
            }
            if(arr[mid] < t){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return false;
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size()-1;
        int i = -1;
        for(i=0; i<n; i++){
            if(target <= matrix[i][m]){
                break;
            }
        }
        if(i == -1 || i == n) return false;
        return search(matrix[i], target);
    }
};