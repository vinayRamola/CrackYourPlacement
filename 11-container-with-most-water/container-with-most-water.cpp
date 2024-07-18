class Solution {
public:
    int maxArea(vector<int>& height) {
        int currAns,maxAns,left,right;
        left=0;
        right = height.size()-1;
        maxAns=0;

        while(left < right){
            int h = min(height[left],height[right]);
            maxAns = max(maxAns,(right-left)*h);
            
            if(height[left] < height[right]) left++;
            else right--;
            
        }   
        return maxAns;
    }
};