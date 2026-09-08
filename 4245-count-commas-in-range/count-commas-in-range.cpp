class Solution {
public:
    int countCommas(int n) {
        if(n>=0 && n<=999) { 
            return 0;
        }
        else if(n>999 && n<=999999) {
            return (n - 999);
        }
        else if(n>999999 && n<=999999999) {
            return (n-999999);
        }
        
        return -1;
        
    }
};