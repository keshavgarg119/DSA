class Solution {
public:
    bool solve(int i, int target, vector<vector<int>>& dp, vector<int>& stones) {
        if(target==0) return true;

        if(i==0) return stones[0]==target;

        if(dp[i][target]!=-1) return dp[i][target];

        bool notTake = solve(i-1, target, dp, stones);
        bool take = false;

        if(target >= stones[i]) {
            take = solve(i-1, target-stones[i], dp, stones);
        }

        return dp[i][target] = take || notTake;
    }

    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();

        int total = accumulate(stones.begin(), stones.end(), 0);

        vector<vector<int>>dp(n, vector<int>(total+1, -1));

        for(int sum = total/2; sum>=0; sum--) {
            if(solve(n-1, sum, dp, stones)) {
                return total - 2*sum;
            }
        }

        return 0;
    }
};