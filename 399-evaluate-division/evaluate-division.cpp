class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string,double>>>graph;

        for(int i=0; i<equations.size(); i++) {
            string u = equations[i][0];
            string v = equations[i][1];

            graph[u].push_back({v,values[i]});
            graph[v].push_back({u,1.0/values[i]});
        }

        vector<double>ans;

        for(auto &q: queries) {
            string src = q[0];
            string des = q[1];

            if(!graph.count(src) || !graph.count(des)) {
                ans.push_back(-1.0);
                continue;
            }

            queue<pair<string, double>>qu;
            unordered_set<string>vis;

            qu.push({src,1.0});
            vis.insert(src);

            double res = -1.0;

            while(!qu.empty()) {
                auto [node, val] = qu.front();
                qu.pop();

                if(node == des) {
                    res = val;
                    break;
                }

                for(auto &[next, wt] : graph[node]) {
                    if(!vis.count(next)) {
                        vis.insert(next);
                        qu.push({next,val*wt});
                    }
                }
            }
            ans.push_back(res);
        }
        return ans;
    }
};