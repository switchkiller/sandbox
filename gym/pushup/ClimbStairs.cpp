class Solution {
public:


    int climbStairs(int n) {
        if (n < 0) return 0;
        if (dp[n] != -1) return dp[n];
        dp[n] = climbStairs(n-1) + climbStairs(n-2);
        return dp[n];
    }

    Solution(){
        memset(dp,-1,sizeof dp);
        dp[0] = 1;
    }

private:
    int dp[10000];
};
