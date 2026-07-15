class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int m = s.size(), n = p.size();
        vector<int> ans;
        vector<int>t1(26,0);
        vector<int>t2(26,0);
        if (m < n)
            return {};
        for (int i = 0; i < n; i++) {
            t1[s[i]-'a']++;
            t2[p[i]-'a']++;
        }
        if (t1 == t2)
            ans.push_back(0);
        for (int i = n; i < m; i++) {
            t1[s[i]-'a']++;
            char left = s[i - n];
            t1[left-'a']--;   
            if (t1 == t2) {
                ans.push_back(i - n + 1);
            }
        }
        return ans;
    }
};