class Solution {
private:
    bool binary_search(vector<vector<int>>& matrix, int target, int i){
        int high = matrix[0].size() - 1;
        int low = 0;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(matrix[i][mid] == target) return true;
            else if(matrix[i][mid] < target) low = mid +1;
            else high = mid - 1;
        }
        return false;
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int low = 0, high = n-1;
        int piv = -1;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(matrix[mid][0] <= target){
                piv = mid;
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        if(piv < 0) return false;
        return binary_search(matrix, target, piv);
    }
};