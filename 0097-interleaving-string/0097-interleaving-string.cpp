class Solution {
public:
    bool check(string& s1, string& s2, string& s3, int i, int j, int k,
               vector<vector<int>>& dp) {
        if (k == s3.length()) {
            return i == s1.length() && j == s2.length();
        }
        bool matchS1 = false;
        bool matchS2 = false;

        if (dp[i][j] != -1)
            return dp[i][j];
        if (i < s1.length() && s1[i] == s3[k]) {
            matchS1 = check(s1, s2, s3, i + 1, j, k + 1, dp);
        }

        if (j < s2.length() && s2[j] == s3[k]) {
            matchS2 = check(s1, s2, s3, i, j + 1, k + 1, dp);
        }

        return dp[i][j] = matchS1 || matchS2;
    }

    bool isInterleave(string s1, string s2, string s3) {
        if (s1.length() + s2.length() != s3.length()) {
            return false;
        }
        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return check(s1, s2, s3, 0, 0, 0, dp);
    }
};
