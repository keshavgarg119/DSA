class Solution {
  public:
    int minMeetingRooms(vector<int> &start, vector<int> &end) {
        // code here
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        
        int room = 0;
        int maxrooms = 0;
        
        int n = start.size();
        int i=0, j=0;
        
        while(i<n) {
            if(start[i] < end[j]) {
                room++;
                i++;
                maxrooms = max(maxrooms, room);
            }
            else {
                room--;
                j++;
            }
        }
        
        return maxrooms;
    }
};
