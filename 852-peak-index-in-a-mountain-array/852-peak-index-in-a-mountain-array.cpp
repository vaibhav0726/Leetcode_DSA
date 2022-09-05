class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int s = 1, e = n-1;
        while(s <= e){ 
            int mid = s + ((e-s)/2);
            if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1]){
                return mid;
            }
            else if(arr[mid] > arr[mid-1] && arr[mid] < arr[mid+1]){
                s = mid+1;
            }
            else{
                e = mid-1;
            }
        }
        return 0;
    }
};