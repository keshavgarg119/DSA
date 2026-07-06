class Solution {
  public:
    int maxPathSum(vector<int> &a, vector<int> &b) {
        // Code here
        int n = a.size();
        int m = b.size();
        
        long long sumA = 0, sumB = 0;
        long long ans = 0;
        
        int i=0, j=0;
        
        while(i<n && j<m) {
            if(a[i] > b[j]) {
                sumB += b[j];
                j++;
            }
            else if(a[i] < b[j]) {
                sumA += a[i];
                i++;
            }
            else {
                ans += max(sumA, sumB);
                ans += a[i];
                
                sumA = 0;
                sumB = 0;
                i++;
                j++;
            }
        }
        
        while(i<n) {
            sumA += a[i];
            i++;
        }
        
        while(j<m) {
            sumB += b[j];
            j++;
        }
        
        ans += max(sumA, sumB);
        
        return ans;
    }
};