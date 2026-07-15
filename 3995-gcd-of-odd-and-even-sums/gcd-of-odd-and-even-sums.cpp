class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int sumEven = 0, sumOdd = 0;

        sumEven = n*(n+1);
        sumOdd = n*n;

        return gcd(sumEven, sumOdd);
    }
};