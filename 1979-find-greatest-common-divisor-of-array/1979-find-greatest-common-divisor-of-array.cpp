class Solution {
public:
    int findGCD(vector<int>& nums) {
         int mx =nums[0];
         int mn = nums[0];
         if(nums.size()<2) return 0;
         if(nums.size()==2) return gcd(nums[0],nums[1]);
         for(auto it:nums) {
             if(it>mx)  mx = it;
             else if(it<mn) mn = it;
         }
         return gcd(mx,mn);
    }
};