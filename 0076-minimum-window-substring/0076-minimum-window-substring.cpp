class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size(), m = t.size();
        if (n < m) return "";
        
        vector<int> hash(256, 0);
        int l = 0, r = 0, mlen = 1e9, si = -1, cnt = 0;
        
        for (int i = 0; i < m; i++) hash[t[i]]++;
        
        while (r < n) {
            if (hash[s[r]] > 0) cnt++;
            hash[s[r]]--;
            
            while (cnt == m) {
                if (r - l + 1 < mlen) {
                    mlen = r - l + 1;
                    si = l;
                }
                
                hash[s[l]]++;
                if (hash[s[l]] > 0) cnt--;
                l++; 
            }
            r++;
        }
        
        return si == -1 ? "" : s.substr(si, mlen);
    }
};
