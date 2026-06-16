class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int>st;
        int maxArea = 0;
        int n = heights.size();

        for(int i=0; i<=n; i++) {
            int currheight = (i==n) ? 0 : heights[i];

            while(!st.empty() && heights[st.top()] > currheight) {
                int height = heights[st.top()];
                st.pop();

                int leftBoundary = st.empty() ? -1 : st.top();

                int width = i - leftBoundary - 1;

                int area = height*width;
                maxArea = max(maxArea, area);
                
            }
            st.push(i);
        }
        return maxArea;
    }
    
};