class Solution {
private: 
    int firstOcc(vector<int>& arr, int n, int target){
        int s = 0, e = n-1;
        int ans = -1;
        while(s <= e){
            int mid = s +((e-s)/2);
            if(arr[mid] == target){
                ans = mid;
                e = mid-1;
            }
            else if(arr[mid] > target){
                e = mid-1;
            }
            else{
                s = mid+1;
            }
        }
        return ans;
    }
    int lastOcc(vector<int>& arr, int n, int target){
        int s = 0, e = n-1;
        int ans = -1;
        while(s <= e){
            int mid = s +((e-s)/2);
            if(arr[mid] == target){
                ans = mid;
                s = mid+1;
            }
            else if(arr[mid] > target){
                e = mid-1;
            }
            else{
                s = mid+1;
            }
        }
        return ans;
    }
public:
    vector<int> searchRange(vector<int>& arr, int target) {
        vector<int> v;
        int n = arr.size();
        v.push_back(firstOcc(arr, n, target));
        v.push_back(lastOcc(arr, n, target));
        return v;
    }
};