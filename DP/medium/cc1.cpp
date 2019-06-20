#good
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int dp[amount+1];
        dp[0] = 0;
        const int n = 1234567;
        for (int i = 1; i < amount+1; i++) dp[i] = n;
        for (int i = 1; i <= amount; i++)
            for (int x = 0; x < coins.size(); x++)
                if (i-coins[x] >= 0)
                    dp[i] = min(dp[i],dp[i-coins[x]]+1);
        if (dp[amount] >= n) return -1; // Very important case, for no change for amount
        return dp[amount];
    }
};
