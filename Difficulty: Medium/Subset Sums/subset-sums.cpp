class Solution {
  public:

    void printSubsetSums(int index, vector<int>& arr, int currSum, vector<int> &sums) {
        if(index==arr.size()) {
            sums.push_back(currSum);
            return;
        }
        
        printSubsetSums(index+1, arr, currSum+arr[index], sums);
        printSubsetSums(index+1, arr, currSum, sums);
    }
    vector<int> subsetSums(vector<int>& arr) {
        // code here
        vector<int>sums;
        
        printSubsetSums(0, arr, 0, sums);
        
        return sums;
    }
};