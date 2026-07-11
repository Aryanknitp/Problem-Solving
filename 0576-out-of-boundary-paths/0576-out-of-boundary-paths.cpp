class Solution {
private:
    int mod = 1e9 + 7;

    int dfs(int m, int n, int maxMove, int r, int c,
            vector<vector<vector<int>>>& dp) {
        if (r < 0 || r >= m || c < 0 || c >= n) {
            return 1;
        }
        if (maxMove == 0) {
            return 0;
        }
        if (dp[r][c][maxMove] != -1) {
            return dp[r][c][maxMove];
        }

        int dr[] = {0, -1, 0, 1};
        int dc[] = {-1, 0, 1, 0};
        long long paths = 0;

        for (int i = 0; i < 4; i++) {
            paths = (paths + dfs(m, n, maxMove - 1, r + dr[i], c + dc[i], dp)) %
                    mod;
        }

        return dp[r][c][maxMove] = paths;
    }

public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> dp(
            m, vector<vector<int>>(n, vector<int>(maxMove + 1, -1)));
        return dfs(m, n, maxMove, startRow, startColumn, dp);
    }
};
