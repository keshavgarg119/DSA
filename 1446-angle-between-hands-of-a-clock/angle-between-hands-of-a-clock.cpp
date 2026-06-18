class Solution {
public:
    double angleClock(int hour, int minutes) {
        // 1min = 6* minutes hand
        // 1hour = 6*, hours hand
        // 5min moves 2.5*, so 1min moves 0.5*

        double movedByHour =  (hour%12)*30 + minutes*0.5;
        double movedByMinutes = minutes*6;

        double result = 0;
        result = abs(movedByHour-movedByMinutes);

        return min(result, 360-result);
    }
};