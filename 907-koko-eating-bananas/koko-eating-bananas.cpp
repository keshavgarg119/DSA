class Solution {
public:
    long long counthours(vector<int>& piles, int capacity) {
        long long hours = 0;

        for(int i=0; i<piles.size(); i++) {
             hours += ((long long)piles[i] + capacity - 1) / capacity;;
        }

        return hours;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        while(low<=high) {
            int mid = low+(high-low)/2;

            long long hours = counthours(piles, mid); 

            if(hours > h) {
                low = mid+1;
            }
            else {
                high = mid-1;
            }

        }

        return low;
    }
};