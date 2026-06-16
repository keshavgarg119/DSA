class Solution {
public:
    string simplifyPath(string path) {
        stack<string>st;

        string curr = "";

        for(int i=0; i<path.size(); i++) {
            if(path[i]!='/') {
                curr += path[i];
            }
            else {
                if(curr=="..") {
                    if(!st.empty()) {
                        st.pop();
                    }
                }
                else if(curr!="" && curr!=".") {
                    st.push(curr);
                }
                curr = "";
            }
        }

        if(curr=="..") {
            if(!st.empty()) {
                st.pop();
            }
        }
        else if(curr!="" && curr!=".") {
            st.push(curr);
        }

        vector<string>temp;

        while(!st.empty()) {
            temp.push_back(st.top());
            st.pop();
        }

        string ans = "";
        reverse(temp.begin(), temp.end());

        for(int i=0; i<temp.size(); i++) {
            ans += "/";
            ans += temp[i];
        }

        return ans.empty() ? "/" : ans;

    }
};