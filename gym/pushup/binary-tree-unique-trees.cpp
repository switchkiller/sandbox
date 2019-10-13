class Solution {
public:
    int numTrees(int n) {
        if (dp[n] != -1) return dp[n];
        dp[n] = 0;
        for (int i = 1; i <= n; i++){
            int left = i-1;
            int right = n-i;
            dp[n] += numTrees(left) * numTrees(right);
        }
        return dp[n];
    }

    Solution(){
        memset(dp, -1, sizeof dp);
        dp[0] = dp[1] = 1;
    }


private:
    int dp[20];
};
