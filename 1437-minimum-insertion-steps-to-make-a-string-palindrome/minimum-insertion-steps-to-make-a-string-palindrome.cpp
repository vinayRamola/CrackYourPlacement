class Solution {
public:
    int solve(string &s,int i,int j,vector<vector<int>> &dp){
        if(i>=j) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        if(s[i]==s[j]){
            return dp[i][j] = solve(s,i+1,j-1,dp);
        }
        return dp[i][j] = 1 + min(solve(s,i+1,j,dp),solve(s,i,j-1,dp));
        
    }
    int minInsertions(string s) {
        int n = s.length();
        // vector<vector<int>> dp(n,vector<int> (n,-1));
        
        // return  solve(s,0,n-1,dp);

        vector<vector<int>> dp(n, vector<int>(n, 0));

        // Fill the DP table
        for (int length = 2; length <= n; ++length) {
            for (int i = 0; i <= n - length; ++i) {
                int j = i + length - 1;
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i+1][j-1];
                } else {
                    dp[i][j] = 1 + min(dp[i+1][j], dp[i][j-1]);
                }
            }
        }
        
        return dp[0][n-1];
        
    }
};

// mbadm
// m d b a d m