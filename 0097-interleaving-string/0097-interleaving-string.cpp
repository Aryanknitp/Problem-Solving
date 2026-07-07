class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.length() + s2.length() != s3.length()) {
            return false;
        }
        int n = s1.length();
        int m = s2.length();
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
        dp[0][0] = true;

        for (int i = 1; i <= n; i++) {
            dp[i][0] = dp[i - 1][0] && (s1[i - 1] == s3[i - 1]);
        }
        for (int j = 1; j <= m; j++) {
            dp[0][j] = dp[0][j - 1] && (s2[j - 1] == s3[j - 1]);
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                bool matchS1 = dp[i - 1][j] && (s1[i - 1] == s3[i + j - 1]);
                bool matchS2 = dp[i][j - 1] && (s2[j - 1] == s3[i + j - 1]);
                dp[i][j] = matchS1 || matchS2;
            }
        }

        return dp[n][m];
    }
};
