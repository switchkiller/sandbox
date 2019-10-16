class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int dp[101][101];
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        dp[1][1] = 1;
        for (int i = 1; i <= m; i++){
            for (int j = 1; j <= n; j++){
                if (obstacleGrid[i-1][j-1] == 0){
                    if (j-2 >= 0 && obstacleGrid[i-1][j-2]==0)
                        dp[i][j] += dp[i][j-1];
                    if ( i-2 >= 0 && obstacleGrid[i-2][j-1]==0)
                        dp[i][j] += dp[i-1][j];
                }
            }
        }
        return dp[m][n];
    }
};
