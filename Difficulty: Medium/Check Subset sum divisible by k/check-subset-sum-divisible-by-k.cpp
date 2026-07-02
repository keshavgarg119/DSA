class Solution {
  public:
    bool divisibleByK(vector<int>& arr, int k) {
        // code here
        vector<bool>dp(k,false);
        
        for(int x: arr) {
            vector<bool>temp = dp;
            
            temp[x % k] = true;
            
            for(int rem = 0; rem<k; rem++) {
                if(dp[rem]) {
                    int newrem = (rem + x) % k;
                    temp[newrem] = true;
                }
            }
            
            dp = temp;
            
            if(dp[0]) return true;
        }
        
        return false;
    }
};