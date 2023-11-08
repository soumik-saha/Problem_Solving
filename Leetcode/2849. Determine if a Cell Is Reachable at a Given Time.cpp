class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int xdiff = abs(fx-sx), ydiff = abs(fy-sy);

        if(xdiff==0 && ydiff==0 && t==1) 
            return false;

        return min(xdiff, ydiff) + abs(xdiff-ydiff) <= t;
    }
};
