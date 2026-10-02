class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size();
        int m = maze[0].size();

        queue<pair<int,int>>q;
        q.push({entrance[0], entrance[1]});

        maze[entrance[0]][entrance[1]] = '+';

        int steps = 0;

        int dr[4] = {+1,-1,0,0};
        int dc[4] = {0,0,+1,-1};

        while(!q.empty()) {
            int size = q.size();
            steps++;

            while(size--) {
                auto [r,c] = q.front();
                q.pop();

                for(int i=0; i<4; i++) {
                    int nr = r + dr[i];
                    int nc = c + dc[i];

                    if(nr<0 || nr>=n || nc<0 || nc>=m) continue;

                    if(maze[nr][nc] == '+') continue;

                    if(nr==0 || nc==0 || nr==n-1 || nc==m-1) return steps;

                    maze[nr][nc] = '+';

                    q.push({nr,nc});
                }
            }
        }

        return -1;
    }
};