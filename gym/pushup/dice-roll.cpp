// class Solution {
// public:
//     long dp[1001];
//     const int MOD = 1e9+7;
//     long numRollsToTargetHelper(int d, int f, int target) {
//         if (d == -1 || target < 0) return 0;
//         if (dp[target] != 0) return dp[target];
//         for (int i = 1; i <= f; i++)
//             dp[target] = (dp[target] + numRollsToTargetHelper(d-1, f, target-i)) % MOD;
//         return dp[target];
//     }
//     int numRollsToTarget(int d, int f, int target) {
//         memset(dp, 0, sizeof dp);
//         dp[0] = 1;
//         return numRollsToTargetHelper(d,f,target);
//     }
// };

class Solution {
public:
    long dp[1001][1001];
    const int MOD = 1e9+7;
    long numRollsToTargetHelper(int d, int f, int target) {
        if (d == -1 || target < 0) return 0;
        if (dp[target][d] != -1) return dp[target][d];
        dp[target][d] = 0;
        for (int i = 1; i <= f; i++)
            dp[target][d] = (dp[target][d] + numRollsToTargetHelper(d-1, f, target-i)) % MOD;
        return dp[target][d];
    }
    int numRollsToTarget(int d, int f, int target) {
        memset(dp, -1, sizeof dp);
        dp[0][0] = 1;
        return numRollsToTargetHelper(d,f,target);
    }
};

// class Solution {
// public:
//     const int MOD = 1e9+7;
//     int numRollsToTarget(int d, int f, int target) {
//         if (d == -1) return 0;
//         if (target == 0) return 1;
//         int num_ways = 0;
//         for (int i = 1; i <= f; i++)
//             num_ways += numRollsToTarget(d-1, f, target-i)%MOD;
//         return num_ways;
//     }
// };
