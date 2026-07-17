class Solution {
public:
    void solve(vector<vector<int>>& grid, vector<vector<int>>& vis, int i,
               int j) {
        int n = grid.size() , m= grid[0].size();
        vis[i][j] = 1;
        vector<int> dr = {-1, 0, 1, 0};
        vector<int> dc = {0, 1, 0, -1};
        for (int k = 0; k < 4; k++) {
            int nr = i + dr[k];
            int nc = j + dc[k];
            if ( nr>=0 && nr<n&& nc>=0 && nc<m && !vis[nr][nc] && grid[nr][nc] == 0) {
                solve(grid, vis, nr, nc);
            }
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 || i == n - 1 || j == 0 || j == m - 1) 
                    if (!vis[i][j] && grid[i][j] == 0) 
                          solve(grid, vis, i, j);
            }
        }
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] == 0) {
                    cnt++;
                    solve(grid, vis, i, j);
                }
            }
        }
        return cnt;
    }
};