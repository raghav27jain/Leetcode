class Solution {
public:
    int rows, cols;
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    void dfs(vector<vector<char>>& board, int row, int col) {
        if(row < 0 || row >= rows || col < 0 || col >= cols) {
            return;
        }
        if(board[row][col] != 'O') {
            return;
        }
        board[row][col]='#';

        for(int k=0;k<4;k++)
        {
            int nr=row+dx[k];
            int nc=col+dy[k];

            dfs(board,nr,nc);
        }
    }
    void solve(vector<vector<char>>& board) {
        rows = board.size();
        cols = board[0].size();

        //Top and Bottom Rows
        for(int j = 0; j < cols; j++) {
            if(board[0][j] == 'O'){
                dfs(board, 0, j);
            }
            if(board[rows-1][j] == 'O'){
                dfs(board, rows-1, j);
            }
        }

        //Left and Right Columns
        for(int i = 0; i < rows; i++){
            if(board[i][0] == 'O'){
                dfs(board, i, 0);
            }
            if(board[i][cols-1] == 'O'){
                dfs(board, i, cols-1);
            }
        }

        //Final Conversion
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
                if(board[i][j] == '#') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};