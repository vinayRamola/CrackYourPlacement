class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mini=nums[0];
        int result=0;

        for(auto &num:nums) mini = min(mini,num);

        for(auto &num:nums) result += num-mini;

        return result;   
    }
};