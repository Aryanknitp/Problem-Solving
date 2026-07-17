class Solution {
public:
    long long gcd(int a ,int b){
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    long long gcdSum(vector<int>& nums) {

        int cm = nums[0];
        vector<int> prefix;

        for(int i=0;i<nums.size();i++){
            cm = max(cm,nums[i]);
            long long gc = gcd(nums[i],cm);
            prefix.push_back(gc);
        }

        sort(prefix.begin(),prefix.end());

        int i =0, j = prefix.size()-1;
        long long sum =0;

        while(i<j){
            sum+=gcd(prefix[i],prefix[j]);
            i++;
            j--;
        }

        return sum;
    }
};