class Solution {
public:
    int dp[1001][2][101];
    int mp(int i, int buy, int mc, vector<int>& prices) {
        if (i == prices.size() || mc == 0)
            return 0;
        if(dp[i][buy][mc]!=-1) return dp[i][buy][mc];
        int profit =0;
        if (buy) {
            profit = max(-prices[i] + mp(i + 1, 0, mc, prices),
                                 0 + mp(i + 1, 1, mc, prices));
        } else {
            profit = max(prices[i] + mp(i + 1, 1, mc - 1, prices),
                                 0 + mp(i + 1, 0, mc, prices));
        }
        return dp[i][buy][mc]  = profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        memset(dp, -1, sizeof(dp));
        return mp(0, 1, k, prices);
    }
};