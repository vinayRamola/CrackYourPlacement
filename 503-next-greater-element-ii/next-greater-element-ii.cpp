class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> nge(n,-1);
        stack<int> st;
        for(int i= 2*n-1;i>=0;i--){
            int index = i%n;
            while(!st.empty() and st.top()<=nums[index]) st.pop();
            if(i<n){
                if(!st.empty()){
                    nge[i]=st.top();
                }
                else{
                    nge[i]=-1;
                }
            }

            st.push(nums[index]);
        }
        return nge;
    }

};