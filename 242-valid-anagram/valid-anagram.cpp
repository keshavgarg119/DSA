class Solution {
public:
    bool isAnagram(string s, string t) {

        // this is the solution, if input doent contains unicode

        if(s.size()!=t.size()) return false;

        // vector<int>freq(26,0);

        // for(char ch: s) {
        //     freq[ch-'a']++;
        // }

        // for(char ch: t) {
        //     freq[ch-'a']--;
        // }   

        // for(int count: freq) {
        //     if(count > 0) return false;
        // }

        // return true;
//..........................................................................
        
        // if unicodes are also contained

        unordered_map<int,int>mp;

        for(char ch: s) {
            mp[ch]++;
        }
        for(char ch: t) {
            mp[ch]--;

            if(mp[ch]<0) return false;
        }

        return true;


    }
};