class Solution {
public:
    int median(vector<int> &nums){
        sort(nums.begin(),nums.end());
        int n=nums.size();

        if(n%2==0) return (n/2);
        else return (n/2);
    }
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        int sum=0;

        // if(n%2==0) center = median(nums)
        // for(auto &num:nums) sum+=num;

        // int avg = sum/n;

        int center = median(nums);

        int res=0;

        for(auto &num: nums) res+= abs(num-nums[center]);
        return res;
    }
};
