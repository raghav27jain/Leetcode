class Solution {
public:
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> dist(rows, vector<int>(cols, -1));

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(mat[i][j] == 0) {
                    q.push({i, j});
                    dist[i][j] = 0;
                }
            }
        }

        while(!q.empty()) {
            auto current = q.front();
            q.pop();
                
            int row = current.first;
            int col = current.second;
            
            for(int k = 0; k < 4; k++) {
                int nr = row + dx[k];
                int nc = col + dy[k];
                if(nr >= 0 && nr < rows && nc >= 0 && nc < cols && dist[nr][nc] == -1) {
                    dist[nr][nc] = dist[row][col] + 1;
                    q.push({nr, nc});
                }
            }
        }
        return dist;
    }
};