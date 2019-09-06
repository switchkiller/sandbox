class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> dp(num+1, 0);
        dp[0] = 0;
        int last_power = -1;
        for (int i = 1; i <= num; i++ ){
            if (pow(2,last_power+1) == i){
                dp[i] = 1;
                last_power++;
            } else{
                dp[i] = dp[pow(2,last_power)] + dp[i-pow(2,last_power)];
            }
        }
        return dp;
    }
};
