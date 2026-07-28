class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int>freq(26,0);

        string leftHalf = "";
        string middle = "";

        for(char c: s) {
            freq[c-'a']++;
        }

        for(int i=0; i<26; i++) {
            leftHalf.append(freq[i]/2, char('a' + i));

            if(freq[i]%2) {
                middle = char('a' + i);
            }
        }

        string rightHalf = leftHalf;
        reverse(rightHalf.begin(), rightHalf.end());

        return leftHalf + middle + rightHalf;
    }
};