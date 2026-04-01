class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        // {position, health, direction, original_index}
        vector<tuple<int, int, char, int>> robots;

        for (int i = 0; i < n; i++) {
            robots.push_back({positions[i], healths[i], directions[i], i});
        }

        // Sort by position
        sort(robots.begin(), robots.end());

        stack<int> st; // Stores the index in the SORTED 'robots' vector
        for (int i = 0; i < n; i++) {
            char dir = get<2>(robots[i]);

            if (dir == 'R') {
                st.push(i);
            } else {
                // Current robot is 'L', check for collisions with 'R' robots in stack
                while (!st.empty() && get<2>(robots[st.top()]) == 'R' && get<1>(robots[i]) > 0) {
                    int topIdx = st.top();
                    int& leftHealth = get<1>(robots[i]);
                    int& rightHealth = get<1>(robots[topIdx]);

                    if (rightHealth < leftHealth) {
                        rightHealth = 0;
                        leftHealth -= 1;
                        st.pop();
                    } else if (rightHealth > leftHealth) {
                        rightHealth -= 1;
                        leftHealth = 0;
                    } else {
                        rightHealth = 0;
                        leftHealth = 0;
                        st.pop();
                    }
                }
                // If 'L' robot survived all collisions (or no 'R' to hit), keep it
                if (get<1>(robots[i]) > 0) {
                    st.push(i);
                }
            }
        }

        // Collect survivors
        vector<pair<int, int>> survivors;
        for (int i = 0; i < n; i++) {
            if (get<1>(robots[i]) > 0) {
                survivors.push_back({get<3>(robots[i]), get<1>(robots[i])});
            }
        }

        // Sort by original index to maintain input order
        sort(survivors.begin(), survivors.end());

        vector<int> result;
        for (auto& p : survivors) {
            result.push_back(p.second);
        }

        return result;
    }
};