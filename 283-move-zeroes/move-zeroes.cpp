class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int ptrZero=0;
        int n = nums.size();

        for(int i=0;i<n;i++){
            if(nums[i]!=0){
                nums[ptrZero++]=nums[i];
            }
        }
        while(ptrZero< nums.size()){
            nums[ptrZero++]=0;
        }
    }
};