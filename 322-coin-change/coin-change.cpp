class Solution {
public:
    int helper(vector<int> coins,int amount,vector<int> &dp){
        
        if(amount==0) return 0;
        if(amount<0) return INT_MAX;

        int res = INT_MAX;

        if(dp[amount]!=-1) return dp[amount];
        
        for(int i=0;i<coins.size();i++){
            if(coins[i]<=amount){
                int sub_res = helper(coins,amount-coins[i],dp);

                if(sub_res!=INT_MAX ){
                    res = min(res, sub_res + 1);
                }
            }
        }
        return dp[amount] = res;
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        
        vector<int> dp(amount+1,-1);
        int ans = helper(coins,amount,dp);
        return (ans!=INT_MAX) ? ans:-1;
    }
};