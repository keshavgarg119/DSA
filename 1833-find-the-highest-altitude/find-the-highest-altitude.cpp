class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int sum = gain[0];
        gain[0] = 0;
        int n = gain.size();
        gain.resize(n+1,-1);
        for(int i=1; i<gain.size(); i++) {
            int temp = gain[i];
            gain[i] = sum;
            sum += temp;
        }

        return *max_element(gain.begin(), gain.end());
    }
};