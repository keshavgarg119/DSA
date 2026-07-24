class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        int maxVal = *max_element(nums.begin(), nums.end());
        int size = 1;
        while (size <= maxVal) size <<= 1;   // smallest power of 2 > maxVal
        size <<= 1;                          // extra headroom for XOR of two such values (safe upper bound)

        // Step 1: all pairwise XOR values
        vector<char> pairXor(size, 0);
        for (int i = 0; i < n; ++i)
            for (int j = i; j < n; ++j)
                pairXor[nums[i] ^ nums[j]] = 1;

        // Step 2: combine pairwise XORs with a third element
        vector<char> tripleXor(size, 0);
        for (int x : nums) {
            for (int v = 0; v < size; ++v) {
                if (pairXor[v]) tripleXor[x ^ v] = 1;
            }
        }

        int ans = 0;
        for (int v = 0; v < size; ++v) ans += tripleXor[v];
        return ans;
    }
};