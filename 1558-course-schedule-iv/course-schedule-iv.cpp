class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>>adj(numCourses);
        vector<int>indegree(numCourses, 0);

        for(auto &it: prerequisites) {
            adj[it[0]].push_back(it[1]);
            indegree[it[1]]++;
        }

        vector<vector<bool>>pre(numCourses, vector<bool>(numCourses, false));
        queue<int>q;
        for(int i=0; i<numCourses; i++) {
            if(indegree[i]==0) {
                q.push(i);
            }
        }
        while(!q.empty()) {
            auto u = q.front();
            q.pop();

            for(int v :  adj[u]) {
                pre[u][v] = true;

                for(int i=0; i<numCourses; i++) {
                    if(pre[i][u]) {
                        pre[i][v] = true;
                    }
                }
                indegree[v]--;
                if(indegree[v]==0) {
                    q.push(v);
                }
            }
        }

        vector<bool>ans;
        for(auto &q: queries) {
            ans.push_back(pre[q[0]][q[1]]);
        }

        return ans;
    }
};