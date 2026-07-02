#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int f = 0, s = 0;
        int n = nums.size();
        unordered_map<int, int> p;
        for (int i = 0; i < n; i++)
        {
            p[nums[i]] = i;
        }
        for (int i = 0; i < n; i++)
        {
            int t = target - nums[i];
            if (p.find(t) != p.end() && i != p[t])
            {
                return {p[t], i};
            }
        }
        return {};
    }
};
