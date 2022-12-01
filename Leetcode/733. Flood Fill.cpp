class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int color = image[sr][sc];
        if(color != newColor)
            dfs(color, newColor, image, sr, sc);
        return image;
    }
private:
    void dfs(int color, int newColor, vector<vector<int>>& image, int sr, int sc){
        if(image[sr][sc] == color){
            image[sr][sc] = newColor;
            if(sr > 0)    dfs(color, newColor, image, sr-1, sc);
            if(sc > 0)    dfs(color, newColor, image, sr, sc-1);
            if(sr < image.size()-1) dfs(color, newColor, image, sr+1, sc);
            if(sc < image[0].size()-1)  dfs(color, newColor, image, sr, sc+1);
        }
    }
};
