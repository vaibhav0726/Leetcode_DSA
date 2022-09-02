class Solution {
public:
    int removeDuplicates(vector<int>& A) {
//       simple approach
        // int count = 0;
        // int n = A.size();
        // for(int i = 1; i<n; i++){
        //     if(A[count] != A[i]){
        //         A[++count] = A[i];
        //     }
        // }
        // return count+1;
        
        
//         Efficient Approach
        int n= A.size();
        int count = 0;
        for(int i = 1; i < n; i++){
            if(A[i] == A[i-1]) count++;
            else A[i-count] = A[i];
        }
        return n-count;
    }
};