class Solution {
    public int maxOperations(int[] nums, int k) {
        int i=0, j=nums.length-1;

        int sum = 0, ans = 0;
        Arrays.sort(nums);

        while(i < j) {
            sum = nums[i] + nums[j];

            if(sum == k) {
                ans += 1;
                i++;
                j--;
            }
            else if(sum < k) {
                i++;
            }
            else {
                j--;
            }
        }

        return ans;

    }
}