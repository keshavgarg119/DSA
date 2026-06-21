class Solution {
public:
    int maxDistance(string moves) {
        int x=0, y=0, any=0;

        for(char ch: moves) {
            if(ch=='U') y++;
            else if(ch=='L') x--;
            else if(ch=='R') x++;
            else if(ch=='D') y--;
            else any++;
        }

        return abs(x) + abs(y) + any;
    }
};