class Solution {
public:
    int solve(vector<int>& cardPoints, int k,int start,int end,vector<vector<int>> &dp){
        if(k==0 or start > end){
            return 0;
        }

        if(dp[start][end]!=-1) return dp[start][end];

        int fromStart = cardPoints[start] + solve(cardPoints,k-1,start+1,end,dp);
        int fromEnd = cardPoints[end] + solve(cardPoints,k-1,start,end-1,dp);

        dp[start][end] = max(fromStart,fromEnd);
    
        return dp[start][end];
    
    }
    int maxScore(vector<int>& cardPoints, int k) {
        // int n = cardPoints.size();
        // int start=0;
        // int end = n-1;
        // if(k>n) return 0;
        
        // vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        // return solve(cardPoints,k,start,end,dp);
        
        int n = cardPoints.size();
        int totalPoints = 0;

        // Calculate the total points of the first k cards
        for (int i = 0; i < k; ++i) {
            totalPoints += cardPoints[i];
        }

        int maxPoints = totalPoints;

        // Use a sliding window to calculate the total points for different combinations
        for (int i = 0; i < k; ++i) {
            totalPoints -= cardPoints[k - 1 - i];
            totalPoints += cardPoints[n - 1 - i];
            maxPoints = max(maxPoints, totalPoints);
        }

        return maxPoints;
    }
};