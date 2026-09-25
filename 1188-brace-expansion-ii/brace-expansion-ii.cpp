class Solution {
public:
    string s;
    int i;

    set<string> parse() {
        set<string> result;
        result.insert("");

        while (i < s.size() && s[i] != '}') {

            if (s[i] == '{') {
                i++; // skip {

                set<string> inside = parse();

                i++; // skip }

                result = multiply(result, inside);
            }
            else if (s[i] == ',') {
                i++; // skip ,

                set<string> next = parse();

                result.insert(next.begin(), next.end());

                break;
            }
            else {
                string ch(1, s[i]);
                i++;

                set<string> temp;
                temp.insert(ch);

                result = multiply(result, temp);
            }
        }

        return result;
    }

    set<string> multiply(set<string>& a, set<string>& b) {
        set<string> result;

        for (string x : a) {
            for (string y : b) {
                result.insert(x + y);
            }
        }

        return result;
    }

    vector<string> braceExpansionII(string expression) {
        s = expression;
        i = 0;

        set<string> ans = parse();

        return vector<string>(ans.begin(), ans.end());
    }
};