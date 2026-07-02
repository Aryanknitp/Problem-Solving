class Solution {
public:
    void solve(vector<vector<int>>& board, int l, int r, int t,
               vector<vector<int>>& v) {
        vector<int> dr = {0, -1, -1, -1, 0, +1, +1, +1};
        vector<int> dc = {-1, -1, 0, +1, +1, +1, 0, -1};
        int m = board.size(), n = board[0].size();
        int cnt = 0;
        // int temp = grid[i][j];
        for (int i = 0; i < 8; i++) {
            int nr = l + dr[i];
            int nc = r + dc[i];
            if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                if (board[nr][nc] == 1)
                    cnt++;
            }
        }
        if (t == 1) {
            if (cnt < 2)
                v[l][r] = 0;
            else if (cnt == 2 || cnt == 3)
                v[l][r] = 1;
            else if (cnt > 3)
                v[l][r] = 0;
        } else if (t == 0 && cnt == 3) {
            v[l][r] = 1;
        }
    }
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> v(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int t = board[i][j];
                solve(board, i, j, t, v);
            }
        }
        board.clear();
        board = v;
    }
};