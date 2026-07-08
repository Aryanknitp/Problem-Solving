class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int totalSum = 0;
        int maxLinear = nums[0];
        int minLinear = nums[0];
        int currentMax = 0;
        int currentMin = 0;

        for (int x : nums) {
            totalSum += x;

            currentMax = max(x, currentMax + x);
            maxLinear = max(maxLinear, currentMax);

            currentMin = min(x, currentMin + x);
            minLinear = min(minLinear, currentMin);
        }

        if (maxLinear < 0) {
            return maxLinear;
        }

        return max(maxLinear, totalSum - minLinear);
    }
};
