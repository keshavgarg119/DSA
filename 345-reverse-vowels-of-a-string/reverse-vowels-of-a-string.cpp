class Solution {
public:
    string reverseVowels(string s) {
        string vowels = "";

        int n = s.size();

        for(int i=0; i<n; i++) {
            if(s[i] == 'i' || s[i] == 'a' || s[i] == 'e' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'I' || s[i] == 'E' || s[i] == 'O' || s[i] == 'U') {
                vowels += s[i];
            }
        }

        reverse(vowels.begin(), vowels.end());

        int j = 0; 

        for(int i=0; i<n; i++) {
            if(s[i] == 'i' || s[i] == 'a' || s[i] == 'e' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'I' || s[i] == 'E' || s[i] == 'O' || s[i] == 'U') {
                s[i] = vowels[j];
                j++;
            }
        }

        return s;
    }
};