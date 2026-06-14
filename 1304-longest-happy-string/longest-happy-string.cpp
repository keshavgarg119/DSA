class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>>pq;

        if(a>0) pq.push({a,'a'});
        if(b>0) pq.push({b,'b'});
        if(c>0) pq.push({c,'c'});
        
        string ans = "";
    
        while(!pq.empty()) {
            auto first = pq.top();
            pq.pop();

            int n = ans.size();

            int count1 = first.first;
            char ch1 = first.second;
            
            if(n>=2 && ans[n-1]==ch1 && ans[n-2]==ch1) {
                
                if(pq.empty()) break;
                
                auto second = pq.top();
                pq.pop();

                int count2 = second.first;
                char ch2 = second.second;

                ans += ch2;
                count2--;

                if(count2>0) {
                    pq.push({count2, ch2});
                }

                pq.push({count1, ch1});
            }
            else {
                ans += ch1;
                count1--;

                if(count1>0) {
                    pq.push({count1, ch1});
                }
            }
        }

        return ans;
    }
};