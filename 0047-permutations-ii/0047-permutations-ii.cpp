class Solution {
public:
    void find(vector<int>& nums, vector<vector<int>>& ans, int idx, int n) {

        if (idx == n) {
            ans.push_back(nums);
            return;
        }
        unordered_set<int> used;

        for (int i = idx; i < nums.size(); i++) {

            if (used.count(nums[i]))
                continue;

            used.insert(nums[i]);

            swap(nums[idx], nums[i]);

            find(nums, ans, idx + 1, n);

            swap(nums[idx], nums[i]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        find(nums, ans, 0, n);
        // vector<vector<int>> res;
        return ans;
    }
};