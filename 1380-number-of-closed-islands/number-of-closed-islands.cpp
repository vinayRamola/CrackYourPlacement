class Solution {
public:
    void dfs(int i,int j,vector<vector<int>>& grid) {
        if (i < 0 || i == grid.size() || j < 0 || j == grid[0].size())
            return;
        if (grid[i][j] == 1)
            return;

        grid[i][j] = 1;

        dfs(i - 1, j, grid);
        dfs(i + 1, j, grid);
        dfs(i, j + 1, grid);
        dfs(i, j - 1, grid);
    }

    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // markthe border as well as the connected 0
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i * j == 0 || i == n - 1 || j == m - 1){
                    if(grid[i][j] == 0)
                        dfs(i, j, grid);
                }
            }
        }

        int res = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) {
                    res++;
                    dfs(i, j, grid);
                }
            }
        }
        return res;
    }
};