class Solution {
public:
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    void dfs(vector<vector<int>>& image, int r, int c, int oldColor, int newColor) {
        int rows = image.size();
        int cols = image[0].size();
        image[r][c] = newColor;
        for(int k = 0; k < 4; k++) {
            int nr = r + dx[k];
            int nc = c + dy[k];
            if(nr >= 0 && nr < rows && nc >= 0 && nc < cols && image[nr][nc]==oldColor) {
                dfs(image, nr, nc, oldColor, newColor);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int color = image[sr][sc];
        if (color == newColor){
            return image;
        }
        dfs(image, sr, sc, color, newColor);
        return image;
    }
};
