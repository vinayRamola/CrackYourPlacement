class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int uniqId = 0;

        for(int i=1;i<nums.size();i++){
            if(nums[i]!=nums[uniqId]){
                nums[++uniqId]=nums[i];
            }
            
        }
        return uniqId+1;      
    }
};