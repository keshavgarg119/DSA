class Solution {
  public:
    int getCount(int n) {
        // code here
        int left = 1;
        int right = 1;
        
        int sum = 1;
        int ans = 0;
        
        while(left <= n/2) {
            if(sum<n) {
                right++;
                sum += right;
            }
            else if(sum>n) {
                sum -= left;
                left++;
            }
            else {
                ans++;
                
                sum-=left;
                left++;
            }
        }
        
        return ans;
    }
};