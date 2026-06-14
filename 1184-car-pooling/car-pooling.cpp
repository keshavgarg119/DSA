class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {

        // sort(trips.begin(), trips.end(), [](vector<int>& a, vector<int>& b) {
        //     return a[1]<b[1];
        // });

        // priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;

        // int currPassengers = 0;
        // for(auto num: trips) {
        //     int passengers = num[0];
        //     int pickup = num[1];
        //     int drop = num[2];

        //     while(!pq.empty() && pq.top().first<=pickup) {
        //         currPassengers -= pq.top().second;
        //         pq.pop();
        //     }

        //     currPassengers += passengers;

        //     if(currPassengers > capacity) {
        //         return false;
        //     }

        //     pq.push({drop, passengers});
        // }

        // return true;

        vector<int>diff(1001,0);

        for(auto it: trips) {
            int passengers = it[0];
            int pickup = it[1];
            int drop = it[2];

            diff[pickup] += passengers;
            diff[drop] -= passengers;
        }

        int currPass = 0;
        for(int i: diff) {
            currPass += i;

            if(currPass > capacity) {
                return false;
            }
        }

        return true;
    }
};