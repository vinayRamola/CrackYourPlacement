class Solution {
public:
    int countPairs(vector<int> &nums,int low,int mid,int high){
        int right = mid+1;
        int count = 0;
        for(int i=low;i<=mid;i++){
            while(right<=high and static_cast<long long>(nums[i]) > 2LL * nums[right]){
                right++;
            }
            count+=right-(mid+1);
        }
        inplace_merge(nums.begin() + low, nums.begin() + mid + 1, nums.begin() + high + 1);
        return count;
    }
    
    int mergeSortandCount(vector<int> &nums,int low,int high){
        if(low>=high) return 0;
            int mid = low + (high-low)/2;
            int count = mergeSortandCount(nums,low,mid)+mergeSortandCount(nums,mid+1,high);
            count += countPairs(nums, low, mid, high);
        
        return count;    
    }

    int reversePairs(vector<int>& nums) {
        return mergeSortandCount(nums,0,nums.size()-1);   
    }
};