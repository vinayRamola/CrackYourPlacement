class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int count1=0;
        for(auto num:nums) if(num==1) count1++;
        int swap=INT_MAX;

        if (count1 == 0 || count1 == n) return 0;

        int curr1=0;
        for(int i=0;i<count1;i++){
            if(nums[i]==1) curr1++;
        }   

        if(curr1==count1) return 0;

        for(int i=1;i<n;i++){
            if(nums[i-1]==1) curr1--;

            if(nums[(i + count1 - 1) % n]==1) curr1++;

            swap = min(swap,count1-curr1);
        }
        return swap;
    }
};