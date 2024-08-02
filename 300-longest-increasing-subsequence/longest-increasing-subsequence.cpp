class Solution {
public:
    int solve(int index,int prev_index,int n,vector<int> &nums,vector<vector<int>> &dp){
        if(index==n){
            return 0;
        }

        if(dp[index][prev_index+1] != -1){
            return dp[index][prev_index+1];
        }

        int take=0;
        if(prev_index == -1 || nums[index] > nums[prev_index]){
            take = 1 + solve(index+1,index,n,nums,dp);
        }
            
        int not_take = 0 + solve(index+1,prev_index,n,nums,dp);

        return dp[index][prev_index+1] = max(take,not_take); 
        
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return solve(0,-1,n,nums,dp);
    }
};