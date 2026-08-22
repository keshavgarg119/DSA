class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0, product = 1, totalSum = 0, temp = n;
        
        while(temp>0) {
            
            sum += temp%10;
            product *= temp%10;
            temp /= 10;
        }

        totalSum = sum + product;
        
        return n % (totalSum) ? false : true;
    }
};