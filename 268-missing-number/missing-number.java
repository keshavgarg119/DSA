class Solution {
    public int missingNumber(int[] nums) {
        int n = nums.length;

        int sum2 = 0;
        int sum = n*(n+1)/2;

        for(int i=0; i<nums.length; i++) {
            sum2 += nums[i];
        }

        return sum - sum2;
    }
}