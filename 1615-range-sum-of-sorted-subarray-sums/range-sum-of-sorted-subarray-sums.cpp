class Solution {
public:
    const int MOD = 1e9+7;
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        int m = n*(n+1)/2;
        vector<int> subArraySum;

        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=i;j<n;j++){
                sum+=nums[j];
                subArraySum.push_back(sum);
            }
        }
        sort(subArraySum.begin(),subArraySum.end());

        int requiredSum=0;
        for(int i=left-1;i<=right-1;i++){
            requiredSum+=subArraySum[i];
            requiredSum%=MOD;
        }

        return requiredSum;
    }
};