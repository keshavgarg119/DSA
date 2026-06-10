class Solution {
public:
    bool isPalindrome(string &s, int start, int end) {
        while(start<=end) {
            if(s[start]!=s[end]) {
                return false;
            }
            start++;
            end--;
        }
        return true;;
    }

    void palindromePart(int index, string &s, vector<string>& subset, vector<vector<string>>& ans) {
        if(index==s.size()) {
            ans.push_back(subset);
            return;
        }

        for(int i=index; i<s.size(); i++) {
            if(isPalindrome(s, index, i)) {
                subset.push_back(s.substr(index, i-index+1));
                palindromePart(i+1, s, subset, ans);
                subset.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string>subset;
        vector<vector<string>>ans;

        palindromePart(0, s, subset, ans);

        return ans;
    }
};