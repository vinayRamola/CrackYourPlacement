class Solution {
public:
    bool isValid(int i,int j,int m,int n){
        return !(i<0 || j<0 || i>=m || j>=n);
    }

    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> ans{{rStart,cStart}};
        int size=rows*cols,len=1;

        int x = rStart, y = cStart;
        while(ans.size() < size){
            for(int j=1; j<=len; j++){
                if(isValid(x,y+j,rows,cols))
                    ans.push_back({x,y+j});
            }

            y+=len;

            for(int i=1;i<=len;i++){
                if(isValid(x+i,y,rows,cols))
                    ans.push_back({x+i,y});
            }

            x+=len;
            len++;

            for(int j=1;j<=len;j++){
                if(isValid(x,y-j,rows,cols))
                    ans.push_back({x,y-j});
            }

            y-=len;

            for(int i=1;i<=len;i++){
                if(isValid(x-i,y,rows,cols))
                    ans.push_back({x-i,y});
            }
            x-=len;
            len++;
        }
        return ans;
    }
};