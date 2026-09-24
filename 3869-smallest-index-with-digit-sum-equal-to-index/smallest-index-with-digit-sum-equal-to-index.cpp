class Solution {
public:
    bool check(int n, int i) {
        int ans = 0;
        while(n>0) {
            ans += n%10;
            n /= 10;
        }

        return ans==i;
    }
    int smallestIndex(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++) {
            if(check(nums[i],i)) {
                return i;
            }
        }

        return -1;
    }
};