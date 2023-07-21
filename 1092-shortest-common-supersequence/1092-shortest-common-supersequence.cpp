class Solution {
private:
    vector<vector<int>> lenOfLCS_Bottom_UP(string str1, string str2, int n, int m){
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));

        for (int i = 0; i <= n; ++i){
            for (int j = 0; j <= m; ++j){
                if(i == 0 || j == 0){
                    dp[i][j] = 0;
                }
                else if(str1[i-1] == str2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        return dp;
    }

    // similar to diff utiliy but difference in ordering
    string findSCS(string str1, string str2, int n, int m, vector<vector<int>> &dp){
        int i=n, j=m;
        string ans = "";
        while(i > 0 && j > 0){
            // meaning both the charachters are equal
            if(str1[i-1] == str2[j-1]){
                ans = str1[i-1] + ans;
                i--; j--;
            }
            else if(dp[i-1][j] > dp[i][j-1]){
                ans = str1[i-1] + ans;
                i--;
            }
            else{
                ans = str2[j-1] + ans;
                j--;
            }
        }
        while(i>0){
            ans = str1[i-1] + ans;
            i--;
        }
        while(j>0){
            ans = str2[j-1] + ans;
            j--;
        }

        return ans;
    }

public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.length();
        int m = str2.length();
        vector<vector<int>> dp = lenOfLCS_Bottom_UP(str1, str2, n, m);
        return findSCS(str1, str2, n, m, dp);
    }
};