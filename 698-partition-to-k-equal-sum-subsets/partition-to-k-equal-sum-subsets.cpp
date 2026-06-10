class Solution {
public:
    bool solve(int index, int target, vector<int>& nums, vector<int>& bucket) {
        if(index==nums.size()) {
            return true;
        }

        for(int i=0; i<bucket.size(); i++) { // remember, we are treing for different different baskets here
            if(bucket[i]+nums[index]>target) {
                continue;
            }

            bucket[i] += nums[index];
            if(solve(index+1, target, nums, bucket)) {
                return true;
            };
            bucket[i] -= nums[index];

            if(bucket[i]==0) break; // avoid the bucket that is not used
            // Avoid duplicate work for identical empty buckets
        }

        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int target = 0;
        int totalsum = 0;

        for(int i=0; i<nums.size(); i++) {
            totalsum += nums[i];
        }

        if(totalsum%k!=0) return false; // partition not possible;

        target = totalsum/k;
        sort(nums.rbegin(), nums.rend());

        if(nums[0]>target) return false; //largest element is greater than target

        vector<int>bucket(k, 0);

        return solve(0, target, nums, bucket);
    }
};