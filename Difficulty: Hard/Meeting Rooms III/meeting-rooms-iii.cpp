class Solution {
  public:
    int mostBooked(int n, vector<vector<int>> &meetings) {
        // code here
        sort(meetings.begin(), meetings.end());
        priority_queue<int, vector<int>, greater<int>>available;
        
        for(int i=0; i<n; i++) {
            available.push(i);
        }
        
        // endtime, roomNumber
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>>occupied;
        vector<int>count(n,0);
        
        for(auto &meeting: meetings) {
            int start = meeting[0];
            int end = meeting[1];
            int duration = end - start;
            
            while(!occupied.empty() && occupied.top().first <= start) {
                available.push(occupied.top().second);
                occupied.pop();
            }
            
            if(!available.empty()) { //room available
                int room = available.top();
                available.pop();
                
                count[room]++;
                occupied.push({end, room});
            }
            else {
                auto [freetime, room] = occupied.top();
                occupied.pop();
                
                count[room]++;
                occupied.push({freetime + duration, room});
            }
        }
        
        int ans = 0;
        for(int i=1; i<n; i++) {
            if(count[i] > count[ans]) {
                ans = i;
            }
        }
        
        return ans;
    }
};