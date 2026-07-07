class Solution {
public:
    int dp[1001][2][101];

    int solve(int i, int buy, int mcount, vector<int>& prices) {
        if (i == prices.size() || mcount == 0)
            return 0;

        if (dp[i][buy][mcount] != -1)
            return dp[i][buy][mcount];

        int profit = 0;

        if (buy) {
            profit = max(-prices[i] + solve(i + 1, 0, mcount, prices),
                         solve(i + 1, 1, mcount, prices));
        } else {
            profit = max(prices[i] + solve(i + 1, 1, mcount - 1, prices),
                         solve(i + 1, 0, mcount, prices));
        }

        return dp[i][buy][mcount] = profit;
    }

    int maxProfit(int k, vector<int>& prices) {
        memset(dp, -1, sizeof(dp));
        return solve(0, 1, k, prices);
    }
};