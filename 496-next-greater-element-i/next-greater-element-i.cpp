class Solution {
public:
    int findIndex(vector<int> &nums2,int ele){
        for(int i=0;i<nums2.size();i++){
            if(nums2[i]==ele) return i;
        }
        return -1;
    }
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int> nextGreater(n,-1);
        for(int i=0;i<n;i++){
            int id = findIndex(nums2,nums1[i]);
            for(int j=id+1;j<m;j++){
                if(nums2[j]>nums1[i]){
                    nextGreater[i]=nums2[j];
                    break;
                }
            }
        }
        return nextGreater;
    }
};