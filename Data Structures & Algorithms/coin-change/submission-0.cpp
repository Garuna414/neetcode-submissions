class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        int len = coins.size();
        sort(coins.begin(), coins.end());
        vector<int> dp(amount+1,amount+1);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            int minCoins = INT_MAX;
            for (int j : coins) {
                if (i - j >= 0 && dp[i-j] >= 0) {
                    minCoins = min(dp[i], dp[i-j]+1);
                }
                if (minCoins == INT_MAX) dp[i] = -1;
                else dp[i] = minCoins;
            }
        }
        if (dp[amount] > 0) return dp[amount];
        return -1;
    }
};
