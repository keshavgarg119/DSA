class Solution {
  public:
    int maxCharGap(string &s) {
        // code here
        vector<int>freq(26,-1);
        int ans = -1;
        
        for(int i=0; i<s.size(); i++) {
            int index = s[i] - 'a';
            if(freq[index]==-1) {
                freq[index] = i;
            }
            else {
                ans = max(ans, i - freq[index]-1);
            }
        }
        
        return ans;
    }
};