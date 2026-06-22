class Solution {
  public:
    int maxArea(vector<int> &height) {
        // code here
        int n = height.size();
        int i = 0;
        int j = n-1;
        int maxArea = 0;
        
        while(i<j) {
            
            int area = min(height[i],height[j])*(j-i-1);
            maxArea = max(maxArea, area);
            
            if(height[i] < height[j]) {
                i++;
            }
            else {
                j--;
            }
        }
        
        return maxArea;
    }
};