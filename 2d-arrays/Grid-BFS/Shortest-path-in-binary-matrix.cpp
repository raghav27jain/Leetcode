class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

        int rows = grid.size();
        int cols = grid[0].size();

        queue<pair<int, int>> q;
        q.push({0, 0});

        if(grid[0][0] == 1) {
            return -1;
        }
        int path = 1;

        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                auto current = q.front();
                q.pop();
                int row = current.first;
                int col = current.second;
                if(row == rows-1 && col == cols-1) {
                    return path;
                }
                for(int k = 0; k < 8; k++) {
                    int nr = row + dx[k];
                    int nc = col + dy[k];
                    if(nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] == 0) {
                        grid[nr][nc] = 1;
                        q.push({nr, nc});
                    }
                }
            }
            path++;
        }
        return -1;
    }
};