class Solution {
public:
    string multiply(string num1, string num2) {

        if (num1 == "0" || num2 == "0") return "0";

        int n1 = num1.size();
        int n2 = num2.size();
        int n = n1 + n2;

        vector<int>result(n,0);

        for(int i=n1-1; i>=0; i--) {
            for(int j=n2-1; j>=0; j--) {
                int mul = (num1[i]-'0')*(num2[j]-'0');
                
                int p1 = i+j+1;
                int p2 = i+j;

                int sum = mul + result[p1];
                result[p2] += sum/10;
                result[p1] =  sum%10;
            }
        }
        string ans;
        for(int digit: result) {
            if(!(ans.empty() && digit==0)) {
                ans.push_back(digit + '0');
            }
        }

        return ans;
    }
};