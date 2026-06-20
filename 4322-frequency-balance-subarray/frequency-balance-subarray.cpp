class Solution {
public:
    int getLength(vector<int>& nums) {

        int n = nums.size();
        int ans = 1;

        for(int i=0; i<n; i++) {
            unordered_map<int,int>freq;
            unordered_map<int,int>freqCnt;

            for(int j=i; j<n; j++) {
                int x = nums[j];

                if(freq[x] > 0) {
                    freqCnt[freq[x]]--;
                    if(freqCnt[freq[x]]==0) {
                        freqCnt.erase(freq[x]);
                    }
                }

                freq[x]++;
                freqCnt[freq[x]]++;

                bool ok = false;

                if(freq.size()==1) {
                    ok = true;
                }
                else if(freqCnt.size()==2) {
                    auto it = freqCnt.begin();
                    
                    int f1 = it->first;
                    ++it;
                    int f2 = it->first;

                    int mini = min(f1,f2);
                    int maxi = max(f1,f2);

                    if(maxi==2*mini) {
                        ok = true;
                    }
                }

                if(ok) {
                    ans = max(ans, j-i+1);
                }
            }
        }
        return ans;
    }
};