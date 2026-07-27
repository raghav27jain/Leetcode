class Solution {
public:
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        int fresh = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 2) {
                    q.push({i, j});
                }
                if(grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        if(fresh == 0) {
            return 0;
        }

        int minutes = 0;
        
        while(!q.empty() && fresh > 0) {
            int size = q.size();
            while(size--) {
                auto current = q.front();
                q.pop();
                int row = current.first;
                int col = current.second;
                for(int k = 0; k < 4; k++) {
                    int nr = row + dx[k];
                    int nc = col + dy[k];
                    if(nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 1) {
                        grid[nr][nc] = 2;
                        fresh--;
                        q.push({nr, nc});
                    }
                }
            }
            minutes++;
        }
        if(fresh == 0) {
            return minutes;
        }
        return -1;
    }
};