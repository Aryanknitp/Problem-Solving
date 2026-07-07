class Solution {
public:
 // sliding window approach
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        if (s.empty() || words.empty()) return ans;

        int wordsize = words[0].size();
        int n = words.size();
        int len = s.size();
        int windowsize = wordsize * n;

        unordered_map<string, int> fq;
        for (const string& w : words) {
            fq[w]++;
        }

        for (int i = 0; i < wordsize; i++) {
            int left = i;
            int right = i;
            unordered_map<string, int> cur;
            int count = 0;

            while (right + wordsize <= len) {
                string curword = s.substr(right, wordsize);
                right += wordsize;

                if (fq.count(curword)) {
                    cur[curword]++;
                    count++;

                    while (cur[curword] > fq[curword]) {
                        string leftword = s.substr(left, wordsize);
                        cur[leftword]--;
                        count--;
                        left += wordsize;
                    }

                    if (count == n) {
                        ans.push_back(left);
                    }
                } else {
                    cur.clear();
                    count = 0;
                    left = right;
                }
            }
        }
        return ans;
    }
};
