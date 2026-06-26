class Solution {
  public:
    vector<int> ans;

    void solve(int n, int lastDigit, int num, int len) {

        if(len == n){
            ans.push_back(num);
            return;
        }

        for(int d = lastDigit + 1; d <= 9; d++){
            solve(n, d, num * 10 + d, len + 1);
        }
    }
    
    vector<int> increasingNumbers(int n) {
        // code here
        if(n==1) {
            vector<int> res;
            for(int i=0; i<=9; i++) {
                res.push_back(i);
            }
            return res;
        }
        
        for (int first = 1; first <= 9; first++) {
            solve(n, first, first, 1);
        }

        return ans;
    }
    
};