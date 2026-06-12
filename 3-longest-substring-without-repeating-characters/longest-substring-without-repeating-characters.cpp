class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();

        int hashLen = 256;
        vector<int>hash(hashLen, -1);

        int maxlen = 0, l=0, r=0;

        while(r<n) {
            if(hash[s[r]]!=-1) {
                l = max(hash[s[r]]+1, l);
            }

            maxlen = max(maxlen, r-l+1);
            
            hash[s[r]] = r;
            r++;
        }

        return maxlen;
    }
};