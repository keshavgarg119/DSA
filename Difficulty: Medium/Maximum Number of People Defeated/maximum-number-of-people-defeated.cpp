class Solution {
  public:
    int maxPeopleDefeated(int p) {
        // Code Here
        long long l = 1, r = 1000000;
        long long ans = 0;
        while(l<=r) {
            long long mid = l + (r-l)/2;
            long long sum = mid * (mid + 1) * (2 * mid + 1) / 6;
            
            if(sum <= p) {
                ans = mid;
                l = mid+1;
            }
            else {
                r = mid-1;
            }
        }
        
        return ans;
    }
};
