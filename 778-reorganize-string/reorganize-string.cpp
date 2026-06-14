class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int>mp;

        for(char ch: s) {
            mp[ch]++;
        }

        priority_queue<pair<int,char>>pq;

        for(auto it: mp) {
            if(it.second > (s.size()+1)/2) {
                return "";
            }

            pq.push({it.second, it.first});
        }

        string ans = "";
        while(pq.size()>=2) {
            auto first = pq.top();
            pq.pop();

            auto second = pq.top();
            pq.pop();

            char ch1 = first.second;
            int freq1 = first.first;

            char ch2 = second.second;
            int freq2 = second.first;

            ans += ch1;
            freq1--;

            ans += ch2;
            freq2--;

            if(freq1>0) {
                pq.push({freq1, ch1});
            }
            if(freq2>0) {
                pq.push({freq2, ch2});
            }
        }

        if(pq.size()==1) {
            ans += pq.top().second;
        }

        return ans;
    }
};