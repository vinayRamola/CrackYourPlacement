class Solution {
public:
    int solveRecurr(string &text1,string &text2,int i,int j,vector<vector<int>> &dp){
        if(i==text1.length() || j== text2.length()) return 0;
        int ans=0;

        if(dp[i][j] != -1) return dp[i][j];

        if(text1[i]==text2[j]){
            ans = 1 + solveRecurr(text1,text2,i+1,j+1,dp); 
        }
        else{
            ans = max(solveRecurr(text1,text2,i+1,j,dp),solveRecurr(text1,text2,i,j+1,dp));
        }

        return dp[i][j] = ans;
    } 
    int longestCommonSubsequence(string text1, string text2) {
        int n,m;
        n=text1.size();
        m=text2.size();

        vector<vector<int>> dp(n+1,vector<int>(m+1,-1) ); 
        return solveRecurr(text1,text2,0,0,dp);
        // int n1 = text1.length();    
        // int n2 = text2.length();

        // vector<vector<int>> dp(n1+1, vector<int>(n2+1,0));

        // for(int i=1;i<=n1;i++){
            
        //     for(int j=1;j<=n2;j++){
        //         int ans=0;
        //         if(text1[i-1] == text2[j-1]){
        //             ans = 1 + dp[i-1][j-1];
        //         }
        //         else{
        //             ans = max(dp[i-1][j],dp[i][j-1]);
        //         }

        //         dp[i][j]=ans;
        //     }
        // }
        // return dp[n1][n2];    
    }
};