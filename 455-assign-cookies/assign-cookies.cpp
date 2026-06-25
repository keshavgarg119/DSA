class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(s.begin(), s.end());
        sort(g.begin(), g.end());

        int contentChild = 0;
        int cookieIndex = 0;

        while(cookieIndex < s.size() && contentChild < g.size()) {
            if(s[cookieIndex] >= g[contentChild]) {
                contentChild++;
            }
            cookieIndex++;
        }

        return contentChild;
    }
};