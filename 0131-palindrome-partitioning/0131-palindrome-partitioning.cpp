class Solution {
public:
    bool isPalindrome(string& palin) {
        int i = 0, j = palin.size() - 1;
        while (i < j) {
            if (palin[i] != palin[j])
                return false;
            i++;
            j--;
        }
        return true;
    }

    void solve(int i, string& s, vector<string>& temp,
               vector<vector<string>>& ans) {
        if (i >= s.size()) {
            ans.push_back(temp);
            return;
        }

        for (int p = i; p < s.size(); p++) {
            string palin = s.substr(i, p - i + 1);
            if (isPalindrome(palin)) {
                temp.push_back(palin);
                solve(p + 1, s, temp, ans);
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        solve(0, s, temp, ans);
        return ans;
    }
};