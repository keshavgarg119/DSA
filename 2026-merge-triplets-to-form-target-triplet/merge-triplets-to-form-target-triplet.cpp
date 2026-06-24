class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int n = triplets.size();
        bool foundX = false, foundY = false, foundZ = false;
        for(int i=0; i<n; i++) {
            if(triplets[i][0] > target[0] || triplets[i][1] > target[1] || triplets[i][2] > target[2]) {
                continue;
            } // all elements must be smaller than target triplets elements

            if(triplets[i][0] == target[0]) {
                foundX = true;
            }
            if(triplets[i][1] == target[1]) {
                foundY = true;
            }
            if(triplets[i][2] == target[2]) {
                foundZ = true;
            }
        }

        return (foundX && foundY && foundZ) ? true : false;
    }
};