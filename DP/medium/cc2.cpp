class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int dp[10000][1000];
        sort(coins.begin(),coins.end());
        for (int i = 0; i < amount+1; i++)
            for (int j = 0; j < coins.size(); j++)
                dp[i][j] = 0;
        //Base case:
        // dp[0][0] = 1,..
        // Dp state:
        // dp[i][j] += dp[i-coins[x]][x]    // if (coins[x] >= coins[j])
        for (int j = 0; j < coins.size(); j++)
            dp[0][j] = 1;

        for (int i = 1; i <= amount; i++)
            for (int j = 0; j < coins.size(); j++)
                for (int k = 0; k < coins.size(); k++)
                    if (i-coins[k] >= 0 && coins[k] >= coins[j])
                        dp[i][j] += dp[i-coins[k]][k];

        return dp[amount][0];
    }
};
