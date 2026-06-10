class Solution {
public:
    void solve(int index, string &curr, vector<string> &result, vector<string>& mapping, string &digits) {
        if(index==digits.size()) {
            result.push_back(curr);
            return;
        }

        string letters = mapping[digits[index] - '0'];

        for(char ch: letters) {
            curr.push_back(ch);
            solve(index+1, curr, result, mapping, digits);
            curr.pop_back();
        }

    }
    vector<string> letterCombinations(string digits) {
        vector<string>result;

        if(digits.empty()) {
            return result;
        }

        vector<string>mapping = {
            "",
            "",
            "abc",
            "def",
            "ghi",
            "jkl",
            "mno",
            "pqrs",
            "tuv",
            "wxyz"
        };

        string curr = "";
        solve(0,curr,result,mapping,digits);

        return result;
    }
};