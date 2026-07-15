class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int m = s.size(), n = p.size();
        vector<int> ans;
        unordered_map<char, int> t1, t2;
        if (m < n)
            return {};
        for (int i = 0; i < n; i++) {
            t1[s[i]]++;
            t2[p[i]]++;
        }
        if (t1 == t2)
            ans.push_back(0);
        for (int i = n; i < m; i++) {
            t1[s[i]]++;
            char left = s[i - n];
            t1[left]--;
            if (t1[left] == 0) {
                t1.erase(left);
            }
            if (t1 == t2) {
                ans.push_back(i - n + 1);
            }
        }
        return ans;
    }
};