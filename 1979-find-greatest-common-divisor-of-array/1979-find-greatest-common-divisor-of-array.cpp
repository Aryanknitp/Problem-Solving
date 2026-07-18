class Solution {
public:
    int findGCD(vector<int>& nums) {
         int mx =nums[0];
         int mn = nums[0];
         for(auto it:nums) {
             if(it>mx)  mx = it;
             else if(it<mn) mn = it;
         }
         return gcd(mx,mn);
    }
};