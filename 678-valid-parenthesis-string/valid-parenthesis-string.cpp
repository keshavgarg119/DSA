class Solution {
public:
    bool checkValidString(string s) {
        // stack<char>open;
        // stack<char>star;

        // for(int i=0; i<s.size(); i++) {
        //     if(s[i]=='(') {
        //         open.push(i);
        //     }
        //     else if(s[i]=='*') {
        //         star.push(i);
        //     }
        //     else {
        //         if(!open.empty()) {
        //             open.pop();
        //         }
        //         else if(!star.empty()) {
        //             star.pop();
        //         }
        //         else {
        //             return false;
        //         }
        //     }
        // }

        // while(!open.empty() && !star.empty()) {
        //     if(open.top() > star.top()) return false;

        //     open.pop();
        //     star.pop();
        // }

        // return open.empty();

        int low = 0, high = 0; // lo = min possible open count, hi = max possible open count

        for(char ch: s) {
            if(ch=='(') {
                low++;
                high++;
            }
            else if(ch==')') {
                low--;
                high--;
            }
            else {
                low--; //trear as "("
                high++; // treat as ")"
            }

            if(high<0) return false; //to many ')' evem in best case

            low = max(low,0); // clamp: '*' can act as empty instead of ')'
        }

        return low==0;
    }
};