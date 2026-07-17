class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int t = n;
        int sumOdd = 0, sumEven = 0;
        int i = 1, j = 1;
        while (true && n > 0) {
            if (i % 2 != 0) {
                sumOdd += i;
                n--;
            }
            i++;
        }
        while (true && t > 0) {
            if (j % 2 == 0) {
                sumEven += j;
                t--;
            }
            j++;
        }
        return gcd(sumOdd, sumEven);
    }
};