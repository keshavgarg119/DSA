class Solution {
public:
    long long sumAndMultiply(int n) {
        int sum = 0;
        long long p = 1;
        long long x = 0;
        
        while(n>0) {
            int digit = n%10;
            if(digit!=0){
                x += digit*p;
                sum += digit;
                p *= 10;
            }
            n = n/10;
        }

        return x*sum;
    }
};