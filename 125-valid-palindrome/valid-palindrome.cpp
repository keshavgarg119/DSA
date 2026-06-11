class Solution {
public:
    bool isPalindrome(string s) {
        string temp = "";

        for(char ch: s) {
            if(isalnum(ch)) {
                temp += tolower(ch);
            }
        }

        int low = 0;
        int high = temp.length()-1;
        while(low<=high) {
            if(temp[low]!=temp[high]) {
                return false;
            }
            low++;
            high--;
        }

        return true;
    }
};