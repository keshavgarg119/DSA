class Solution {
public:
    bool solve(int index, int target, vector<int>& sides, vector<int>& matchsticks) {
        if(index==matchsticks.size()) {
            return sides[0]==target &&
                   sides[1]==target &&
                   sides[2]==target &&
                   sides[3]==target;
        }

        for(int i=0; i<4; i++) {
            if(sides[i] + matchsticks[index] > target) continue;

            sides[i] += matchsticks[index];
            if(solve(index+1, target, sides, matchsticks)) {
                return true;
            }
            sides[i] -= matchsticks[index];

            if(sides[i]==0) break;
        }

        return false;
    }
    bool makesquare(vector<int>& matchsticks) {
        int sum = accumulate(matchsticks.begin(), matchsticks.end(),0);

        int n = matchsticks.size();
        if(sum%4!=0) return false;

        int target = sum/4;

        sort(matchsticks.rbegin(), matchsticks.rend());

        if(matchsticks[0]>target) return false;

        vector<int>sides(4,0);

        return solve(0,target,sides,matchsticks);
    }
};