class Solution {
public:
    bool checkGoodInteger(int n) {
        int squareSum = 0;
        int digitSum = 0;
        while(n>0) {
            int d = n%10;
            squareSum += d*d;
            digitSum += d;
            n /= 10;
        }

        return ((squareSum-digitSum) >= 50) ? true : false;
    }
};