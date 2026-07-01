class Solution {
public:
    void solve(vector<vector<int>>& result, vector<int>& current, int i, int k,
               int n) {

        if (current.size() == k) {
            result.push_back(current);
            return;
        }
        for (int j = i; j <= n; j++) {
            current.push_back(j);
            solve(result, current, j + 1, k, n);
            current.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> current;
        solve(result, current, 1, k, n);
        return result;
    }
};