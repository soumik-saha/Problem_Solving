class Solution {
public:
    bool isPathCrossing(string path) {
        vector<pair<int, int>> visited;
        visited.push_back({0,0});
        int curX = 0, curY = 0;

        for(int i=0; i<path.size(); i++) {
            switch(path[i]) {
                case 'N':
                    curY++;
                    break;
                case 'S':
                    curY--;
                    break;
                case 'E':
                    curX++;
                    break;
                case 'W':
                    curX--;
                    break;
            }
            visited.push_back({curX, curY});
            if(count(visited.begin(), visited.end(), make_pair(curX, curY)) > 1) 
                return true;
        }
        return false;
    }
};
