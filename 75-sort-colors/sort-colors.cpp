class Solution {
public:
    void sortColors(vector<int>& nums) {
        // int n = nums.size();
        // int left,middle,right;
        // left=0;
        // middle=0;
        // right=n-1;
        // while(middle<=right){
        //     if(nums[middle]==2){
        //         swap(nums[right],nums[middle]);
        //         right--;
        //     }
        //     else if(nums[middle]==0){
        //         swap(nums[left],nums[middle]);
        //         left++;
        //         middle++;
        //     }
        //     else{
        //         middle++;
        //     }
        // }

        int zero=-1;
        int one=-1;
        int two=-1;

        for(auto &num:nums){
            if(num==0){
                nums[++two] = 2;
                nums[++one] = 1;
                nums[++zero] = 0;
            }
            else if(num==1){
                nums[++two] = 2;
                nums[++one] = 1;
            }
            else{
                nums[++two] = 2;
            }
        }
    }
};

