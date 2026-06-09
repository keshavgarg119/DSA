class Solution {
public:
    
    int countDay(vector<int>& weights, int capacity) {
        int days = 1, load = 0;

        for(int i=0; i<weights.size(); i++) {
            if(weights[i]+load <= capacity) {
                load += weights[i];
            }
            else {
                days++;
                load = weights[i];
            }
        }

        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);

        while(low<=high) {
            int mid = low + (high-low)/2;
            int countDays = countDay(weights, mid);

            if(countDays <= days) {
                high = mid-1;
            }
            else {
                low = mid+1;
            }
        }

        return low;
    }
};