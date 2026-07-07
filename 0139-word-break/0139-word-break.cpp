class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // using set and dp solution
        //.. store ans at the last index of strign length
        unordered_set<string> st;
        int mlen = 0;
        for (int i = 0; i < wordDict.size(); i++) {
            st.insert(wordDict[i]);
            int l = wordDict[i].length();
            mlen = max(mlen, l);
        }
        int n = s.size();
        vector<int> dp(n + 1);
        dp[0] = true;
        for (int i = 1; i <= n; i++) {
            for (int j = i-1; j >= max(0, i - mlen); j--) {
                if (dp[j] && st.contains(s.substr(j, i-j))) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};