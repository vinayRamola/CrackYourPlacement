class Solution {
public:
    bool magicSquare(vector<vector<int>> &grid,int r,int c){
        
        set<int> nums;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                int val = grid[r + i][c + j];
                if (val < 1 || val > 9 || !nums.insert(val).second) {
                    return false;  // Not in range or not distinct
                }
            }
        }


        for(int i=0;i<3;i++){
            int sum=0;
            for(int j=0;j<3;j++){
                sum+=grid[r+i][c+j];
            }
            if(sum!=15) return false;
        }

        for(int i=0;i<3;i++){
            int sum=0;
            for(int j=0;j<3;j++){
                sum+=grid[r+j][c+i];
            }
            if(sum!=15) return false;
        }

        int sumDig1=0;
            int sumDig2=0;

        for(int i=0;i<3;i++){
            sumDig1+=grid[r+i][c+i];
            sumDig2+=grid[r+2-i][c+2-i];
        }
        if(sumDig2!=15) return false;

        return true;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count=0;

        for(int i=0;i<m-2;i++){
            for(int j=0;j<n-2;j++){
                if(magicSquare(grid,i,j)){
                    count++;
                }
            }
        }
        return count;
    }
};