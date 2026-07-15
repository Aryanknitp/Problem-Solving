#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int numSquares(int n) {
        // dp[i] stores the minimum number of perfect squares to sum up to i
        vector<int> dp(n + 1, INT_MAX);
        
        // Base case
        dp[0] = 0; 
        
        // Outer loop: Compute values for all numbers from 1 to n
        for (int i = 1; i <= n; i++) {
            // Inner loop: Check all perfect squares smaller than or equal to i
            for (int j = 1; j * j <= i; j++) {
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }
        
        return dp[n];
    }
};
