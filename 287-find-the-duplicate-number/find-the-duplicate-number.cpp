class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];

        do{
            slow= nums[slow];
            fast = nums[nums[fast]];
        }while(slow!=fast);

        slow=nums[0];

        while(slow!=fast){
            slow = nums[slow];
            fast=nums[fast];
        }

        return slow;
    }
};

// class Solution {
// public:
//     int findDuplicate(vector<int>& nums) {
//         int n = nums.size();
//         // sort(nums.begin(),nums.end());

//         // for(int i=0;i<n-1;i++){
//         //     if(nums[i]==nums[i+1]){
//         //         return nums[i];
//         //     }
//         // }
//         // return -1;

//         unordered_map<int,int> mp;
//         for(auto num:nums){
//             if(mp[num]==1) return num;
//             else mp[num]++;
//         } 
        
//         return -1;
//     }
// };