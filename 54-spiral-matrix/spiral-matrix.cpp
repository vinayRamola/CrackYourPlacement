class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (n == 0) {
            // Empty matrix
            return {};
        }
        int m = matrix[0].size();
        int left,right,top,bottom;

        vector<int> ans;
        
        left=top=0;
        right = m-1;
        bottom = n-1;

        while(top<=bottom and left <=right){
            for(int i=left;i<=right;i++){
                ans.push_back(matrix[top][i]);
            }
            top++;

            for(int i=top;i<=bottom;i++){
                ans.push_back(matrix[i][right]);
            }

            right--;

            if(top<=bottom){
                for(int i=right;i>=left;i--){
                ans.push_back(matrix[bottom][i]);
            }
                bottom--;
            }

            if(left<=right){
                for(int i=bottom;i>=top;i--){
                ans.push_back(matrix[i][left]);
            }
            left++;
            }
        }

        return ans;
    }
};