#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        // Record the last occurrence index of each character
        vector<int> last_idx(26, 0);
        for (int i = 0; i < s.size(); i++) {
            last_idx[s[i] - 'a'] = i;
        }
        
        vector<int> partitions;
        int start = 0;
        int end = 0;
        
        // Traverse the string to find partition boundaries
        for (int i = 0; i < s.size(); i++) {
            // Expand the current partition window to include the last occurrence of s[i]
            end = max(end, last_idx[s[i] - 'a']);
            
            // If the current index reaches the end of the partition window
            if (i == end) {
                partitions.push_back(end - start + 1);
                start = i + 1; // Move start to the beginning of the next partition
            }
        }
        
        return partitions;
    }
};
