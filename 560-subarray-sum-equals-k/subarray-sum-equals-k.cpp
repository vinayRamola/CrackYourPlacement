class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int cnt,preSum,n;
        n = nums.size();
        cnt=preSum=0;
        unordered_map<int,int> mpp;

        mpp[0] = 1;

        for(int i=0;i<n;i++){
            preSum += nums[i];
            int compliment = preSum-k;
            cnt += mpp[compliment];
            mpp[preSum]+=1;
        }
        return cnt;
    }
};


