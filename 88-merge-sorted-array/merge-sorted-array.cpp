class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=m-1;
        int j=n-1;
        int index = m+n-1;
        while(index>=0){
            if(i>=0 and j>=0){
                if(nums1[i] < nums2[j]) nums1[index--]=nums2[j--];
                else nums1[index--]=nums1[i--];
            }
            else if(j>=0){
                nums1[index--]=nums2[j--];
            }
            else break;
        }
    }
};