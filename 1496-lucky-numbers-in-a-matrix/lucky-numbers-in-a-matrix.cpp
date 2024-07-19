class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();

        vector<int> rowMin(row,INT_MAX);
        vector<int> colMax(col,INT_MIN);

        // Find the minimum element in each row
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                rowMin[i] = min(rowMin[i], matrix[i][j]);
            }
        }

        // Find the maximum element in each column
        for (int j = 0; j < col; ++j) {
            for (int i = 0; i < row; ++i) {
                colMax[j] = max(colMax[j], matrix[i][j]);
            }
        }

        vector<int> res;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(rowMin[i]==colMax[j]){
                    res.push_back(rowMin[i]);
                }
            }
        }


        return res;
    }
};

// [
// [3,7,8],
// [9,11,13],
// [15,16,17]]

// [[1,10,4,2]
// ,[9,3,8,7]
// ,[15,16,17,12]]

// 1 3 12
// 15 16 17 12