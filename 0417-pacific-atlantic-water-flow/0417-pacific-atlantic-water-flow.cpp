class Solution {
public:
    void dfs(int r, int c, vector<vector<bool>>& visited, int prevHeight, vector<vector<int>>& heights, int n, int m) {
        // Return if out of bounds, already visited, or if the water cannot flow uphill
        if (r < 0 || r >= n || c < 0 || c >= m || visited[r][c] || heights[r][c] < prevHeight) {
            return;
        }
        
        visited[r][c] = true;
        
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        
        for (int i = 0; i < 4; i++) {
            dfs(r + dr[i], c + dc[i], visited, heights[r][c], heights, n, m);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        if (heights.empty() || heights[0].empty()) return {};
        
        int n = heights.size();
        int m = heights[0].size();
        
        vector<vector<bool>> pacific(n, vector<bool>(m, false));
        vector<vector<bool>> atlantic(n, vector<bool>(m, false));
        
        // 1. Traverse from Left and Right borders
        for (int i = 0; i < n; i++) {
            dfs(i, 0, pacific, heights[i][0], heights, n, m);     // Left border (Pacific)
            dfs(i, m - 1, atlantic, heights[i][m - 1], heights, n, m); // Right border (Atlantic)
        }
        
        // 2. Traverse from Top and Bottom borders
        for (int j = 0; j < m; j++) {
            dfs(0, j, pacific, heights[0][j], heights, n, m);     // Top border (Pacific)
            dfs(n - 1, j, atlantic, heights[n - 1][j], heights, n, m); // Bottom border (Atlantic)
        }
        
        // 3. Find cells reachable by both oceans
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }
        
        return ans;
    }
};
