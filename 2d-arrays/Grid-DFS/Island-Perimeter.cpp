class Solution {
public:
    int rows, cols;

    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    int dfs(vector<vector<int>>& grid, int row, int col) {

        // Outside grid
        if(row < 0 || row >= rows || col < 0 || col >= cols)
            return 1;

        // Water
        if(grid[row][col] == 0)
            return 1;

        // Already visited
        if(grid[row][col] == -1)
            return 0;

        // Mark visited
        grid[row][col] = -1;

        int perimeter = 0;

        for(int k = 0; k < 4; k++) {

            int nr = row + dx[k];
            int nc = col + dy[k];

            perimeter += dfs(grid, nr, nc);
        }

        return perimeter;
    }

    int islandPerimeter(vector<vector<int>>& grid) {

        rows = grid.size();
        cols = grid[0].size();

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(grid[i][j] == 1)
                    return dfs(grid, i, j);
            }
        }

        return 0;
    }
};