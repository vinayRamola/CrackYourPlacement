class Solution {
public:
    int solve(string s,int index,int bCount,vector<vector<int>> &dp){
        if(index==s.length()) return 0;

        if(dp[index][bCount]!=-1) return dp[index][bCount];

        if(s[index] == 'b') dp[index][bCount] = solve(s,index+1,bCount+1,dp);
        else{
            int removeA = 1 + solve(s,index+1,bCount,dp); // delete current a
            int removeB = bCount +solve(s,index+1,0,dp); // delete previous b

            dp[index][bCount] = min(removeA,removeB);
        }
        return dp[index][bCount];
    }
    int minimumDeletions(string s) {
        int n = s.length();
        int bCount=0;

        // vector<vector<int>> dp(n,vector<int>(n,-1));
        // return solve(s,0,bCount,dp);

        vector<int> dp(n+1,0);

        for(int i=1;i<=n;i++){
            if(s[i-1]=='b'){
                dp[i]=dp[i-1];
                bCount++;
            }
            else{
                dp[i] = min(dp[i-1]+1,bCount);
            }
        }
        return dp[n];
    }
};