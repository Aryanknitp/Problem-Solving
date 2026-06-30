class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int>counts(3,0);
        int n = s.size();
        int left = 0;
        int count = 0;
        // unordered_map<char, int> mp;
        for(int r=0;r<s.size();r++) {
                counts[s[r] - 'a']++;
            
            while (counts[0] > 0 && counts[1] > 0 && counts[2] > 0) {
                count += n - r;
                counts[s[left] - 'a']--;
                left++;
            }
        }
        return count;
    }
};