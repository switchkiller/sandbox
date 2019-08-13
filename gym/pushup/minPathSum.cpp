class Solution {
public:
    int dp[1000][1000];

    int minPathSumUtil(vector<vector<int>>& grid, int x, int y){
        if (x < 0 || y < 0) return INT_MAX;
        if (dp[x][y] != -1) return dp[x][y];
        if (x == 0 && y == 0) return grid[0][0];
        dp[x][y] = grid[x][y] + min(minPathSumUtil(grid,x-1,y), minPathSumUtil(grid,x,y-1));
        return dp[x][y];
    }

    int minPathSum(vector<vector<int>>& grid) {
        int x = grid.size(), y = grid[0].size();
        for (int i = 0; i < x; i++ ){
            for (int j = 0; j < y; j++){
                dp[i][j] = -1;
            }
        }

        return minPathSumUtil(grid,x-1,y-1);
    }
};
