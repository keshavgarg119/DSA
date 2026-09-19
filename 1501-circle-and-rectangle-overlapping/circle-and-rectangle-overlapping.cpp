class Solution {
public:
    bool checkOverlap(int radius, int xc, int yc,
                      int x1, int y1, int x2, int y2) {
        
        // Find closest x-coordinate on rectangle
        int closestX = max(x1, min(xc, x2));
        
        // Find closest y-coordinate on rectangle
        int closestY = max(y1, min(yc, y2));
        
        // Distance squared between circle center
        // and closest point on rectangle
        int dx = xc - closestX;
        int dy = yc - closestY;
        
        return dx * dx + dy * dy <= radius * radius;
    }
};