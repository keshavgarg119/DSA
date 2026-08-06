class Solution {
public:
    bool productDigits(int temp, int t) {
        int product = 1;
        while(temp>0) {
            int digit = temp%10;
            temp /= 10;
            product *= digit;
        }

        return product%t==0;
    }
    
    int smallestNumber(int n, int t) {
        int temp = n;
        
        while(true) {
            if(productDigits(temp, t)) {
                return temp;
            }
            temp++;
        }
        
        
        return temp;
    }
};