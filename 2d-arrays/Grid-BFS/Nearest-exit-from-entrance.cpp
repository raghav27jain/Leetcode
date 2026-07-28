class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};
        int rows = maze.size();
        int cols = maze[0].size();
        queue<pair<int, int>> q;
        q.push({entrance[0], entrance[1]});
        maze[entrance[0]][entrance[1]] = '+';
        int steps = 0;
        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                auto current = q.front();
                q.pop();
                int row = current.first;
                int col = current.second;
                if((row == rows-1 || col == cols-1 || row == 0 || col == 0) && !(row == entrance[0] && col == entrance[1])) {
                    return steps;
                }

                for(int k = 0; k < 4; k++) {
                    int nr = row + dx[k];
                    int nc = col + dy[k];
                    if(nr >= 0 && nr < rows && nc >= 0 && nc < cols && maze[nr][nc] == '.') {
                        maze[nr][nc] = '+';
                        q.push({nr, nc});
                    }
                }
            }
            steps++;
        }
        return -1;
    }
}; 