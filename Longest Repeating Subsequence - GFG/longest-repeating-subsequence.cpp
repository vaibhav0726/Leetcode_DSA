//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private:
    int lenOfLCS_Bottom_UP(string str1, string str2, int n, int m){
    	vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
    
    	for (int i = 0; i <= n; ++i){
    		for (int j = 0; j <= m; ++j){
    			if(i == 0 || j == 0){
    				dp[i][j] = 0;
    			}
    			else if(str1[i-1] == str2[j-1] && i!=j){
    				dp[i][j] = 1 + dp[i-1][j-1];
    			}
    			else{
    				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    			}
    		}
    	}
    
    	return dp[n][m];
    }
	public:
		int LongestRepeatingSubsequence(string str){
		    int n = str.length();
	        return lenOfLCS_Bottom_UP(str, str, n, n);
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends