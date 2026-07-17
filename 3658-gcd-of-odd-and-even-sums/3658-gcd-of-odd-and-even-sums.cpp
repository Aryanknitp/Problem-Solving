class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        // int t = n;
       long long f  = n*n;
       long long s = n* (n+1);
       return gcd(f,s);
    }
};