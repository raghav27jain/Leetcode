class Solution {
public:
    int dx[4] = {-1, 1 , 0, 0};
    int dy[4] = {0, 0, -1, 1};
    int dfs(int row, int col, vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        grid[row][col] = 0;
        int area = 1;
        for(int k = 0; k < 4; k++) {
            int nr = row + dx[k];
            int nc = col + dy[k];
            if(nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] == 1) {
                area += dfs(nr, nc, grid);
            }
        }
        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maximum = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(grid[i][j] == 1) {
                    int area = dfs(i, j, grid);
                    maximum = max(maximum, area);
                }
            }
        }
        return maximum;
    }
};