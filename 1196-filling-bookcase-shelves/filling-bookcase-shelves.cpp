class Solution {
public:
    int solve(vector<vector<int>> &books,int index,int shelfWidth,vector<int> &memo){
        if(index==books.size()) return 0;

        if(memo[index]!=-1) return memo[index];

        int width=0,height=0,minHeight=INT_MAX;

        for(int i=index;i<books.size();i++){
            width += books[i][0];
            if(width>shelfWidth) break;
            height = max(height,books[i][1]);
            minHeight = min(minHeight,height+solve(books,i+1,shelfWidth,memo));
        }

        return memo[index] = minHeight;
    }
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int minHeight = 0;
        int n = books.size();
        vector<int> memo(n+1,-1);
        return solve(books,0,shelfWidth,memo);
    }
};