class Solution {
public:
    int median(vector<int> &nums){
        sort(nums.begin(),nums.end());
        int n=nums.size();

        return n/2;
    }
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        int sum=0;

        int center = median(nums);

        int res=0;

        for(auto &num: nums) res+= abs(num-nums[center]);
        return res;
    }
};
