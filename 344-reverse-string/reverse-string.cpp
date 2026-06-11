class Solution {
public:
    void reverseString(vector<char>& s) {
        // vector<char>ans;
        // ans = s;

        // for(int i=ans.size()-1; i>=0; i--) {
        //     s.push_back(ans[i]);
        // }

        reverse(s.begin(), s.end());

    }
};