class DetectSquares {
public:
    unordered_map<int, unordered_map<int,int>>cnt;
    vector<pair<int,int>>points;

    DetectSquares() { }
    
    void add(vector<int> point) {
        int x = point[0];
        int y = point[1];

        cnt[x][y]++;
        points.push_back({x,y});
    }
    
    int count(vector<int> point) {
        int x = point[0];
        int y = point[1];

        int ans = 0;

        for(auto &[x2,y2] : points) {
            if(x==x2 || y==y2) continue;

            if(abs(x-x2) != abs(y-y2)) continue;

            ans += cnt[x][y2]*cnt[x2][y];
        }

        return ans;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */