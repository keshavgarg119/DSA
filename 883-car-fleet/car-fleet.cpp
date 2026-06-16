class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();

        vector<pair<int,double>> cars; //{position, time}

        for(int i=0; i<n; i++) {
            double time = (double)(target-position[i])/speed[i];
            cars.push_back({position[i], time});
        }

        sort(cars.begin(), cars.end());

        int fleets = 0;
        double maxTime = 0;

        for(int i=n-1; i>=0; i--) {
            double currTime = cars[i].second;

            if(currTime > maxTime) {
                fleets++;
                maxTime = currTime;
            }
        }

        return fleets;
    }
};