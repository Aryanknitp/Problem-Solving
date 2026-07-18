class Solution {
public:
    void find(vector<int>& nums, set<vector<int>>& ans, int s, int n) {

        if (s == n) {
            ans.insert(nums);
            return;
        }
        for (int i = s; i < n; i++) {
            swap(nums[s], nums[i]);
            find(nums, ans, s + 1, n);
            swap(nums[s], nums[i]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> ans;
        int n = nums.size();
        // vector<int> temp;
        find(nums, ans, 0, n);
        vector<vector<int>> res;
        for (auto it : ans) {
            res.push_back(it);
        }
        return res;
    }
};