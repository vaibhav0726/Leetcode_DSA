//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> nums, int n){
        // Your code here
        
        vector<long long> ans(n,0);
        stack<int> st;
        for(int i=0; i<n; i++){
            while(!st.empty() && nums[st.top()]<nums[i]){
                ans[st.top()] = nums[i];
                st.pop();
            }
            st.push(i);
        }
        for(int i=0; i<n; i++){
            if(ans[i] == 0){
                ans[i] = -1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution obj;
        vector <long long> res = obj.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}
// } Driver Code Ends