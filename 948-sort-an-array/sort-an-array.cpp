class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int minEle = INT_MAX;
        int maxEle = INT_MIN;
        unordered_map<int,int> mp;

        for(auto num:nums){
            mp[num]++;
            minEle = min(minEle,num);
            maxEle = max(maxEle,num);
        }
        int j=0;
        for(int i=minEle;i<=maxEle;i++){
            if(mp.find(i)!=mp.end()){
                int count = mp[i];
                while(count--){
                    nums[j++]=i;
                }
            }
        }
        return nums;
    }
};