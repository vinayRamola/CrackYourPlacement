class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int row = rowSum.size();
        int col = colSum.size();

        vector<vector<int>> matrix(row,vector<int>(col));

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                int x = min(rowSum[i],colSum[j]);
                matrix[i][j]=x;
                rowSum[i]-=x;
                colSum[j]-=x;
            }
        }
        return matrix;
    }
};