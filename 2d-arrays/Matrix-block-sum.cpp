class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        //Build a prefix matrix
        vector<vector<int>> prefix;
        int r = mat.size();
        int c = mat[0].size();
        prefix.assign(r, vector<int>(c));
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                int up = (i > 0) ? prefix[i-1][j] : 0;
                int left = (j > 0) ? prefix[i][j-1] : 0;
                int diag = (i > 0 && j > 0) ? prefix[i-1][j-1] : 0;
                prefix[i][j] = up + left - diag + mat[i][j];
            }
        }

        //Process every cell 
        vector<vector<int>> ans(r, vector<int>(c));
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                int r1 = max(0, i - k);
                int c1 = max(0, j - k);
                int r2 = min(r - 1, i + k);
                int c2 = min(c - 1, j + k);

                //Calculate Sum
                int total = prefix[r2][c2];
                int up = (r1 > 0) ? prefix[r1-1][c2] : 0;
                int left = (c1 > 0) ? prefix[r2][c1-1] : 0;
                int diag = (r1 > 0 && c1 > 0) ? prefix[r1-1][c1-1] : 0;

                ans[i][j] = total - up - left + diag;
            }
        }
        return ans;
    }
};