
class Solution {
public:
    void solve(vector<int>& ans, vector<vector<int>>& res, int i, int k,
               int n) {
        if (k == 0) {
            res.push_back(ans);
            return;
        }
        if (i > n) {
            return;
        }
        ans.push_back(i);
        solve(ans, res, i + 1, k - 1, n);
        ans.pop_back();

        solve(ans, res, i + 1, k, n);
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        for (int i = 1; i <= n - k + 1; i++) {
            vector<int> ans;
            ans.push_back(i);
            solve(ans, res, i + 1, k - 1, n);
        }
        return res;
    }
};
