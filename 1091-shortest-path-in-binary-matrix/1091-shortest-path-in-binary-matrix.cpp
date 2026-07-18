class Solution {
public:
    void solve(int& mxlen, vector<vector<int>>& vis, vector<vector<int>>& grid,
               queue<pair<int, int>>& q, int len, int r, int c) {
        int n = grid.size();
        vis[r][c] = 1;
        
        int dr[] = {-1, -1, 0, 1, 1, 1, 0, -1};
        int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};
        
        while (!q.empty()) {
            // FIX 1: Track layer sizes to safely increment 'len' level-by-level
            int size = q.size();
            while (size--) {
                int r1 = q.front().first;
                int c1 = q.front().second;
                q.pop(); // FIX 2: Pop from the queue to prevent an infinite loop

                // FIX 3: Check for destination inside the BFS loop
                if (r1 == n - 1 && c1 == n - 1) {
                    mxlen = min(mxlen, len);
                    return; 
                }

                for (int k = 0; k < 8; k++) {
                    int nr = r1 + dr[k];
                    int nc = c1 + dc[k];
                    if (nr >= 0 && nr < n && nc >= 0 && nc < n && !vis[nr][nc] &&
                        grid[nr][nc] == 0) {
                        vis[nr][nc] = 1; // FIX 4: Mark visited IMMEDIATELY when found
                        q.push({nr, nc});
                    }
                }
            }
            len++; // FIX 1: Increment length only after finishing an entire level
        }
    }
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int mxlen = INT_MAX, len = 1;
        vector<vector<int>> vis(n, vector<int>(n, 0));
        queue<pair<int, int>> q;
        
        // FIX 5: Fix entry logic check (grid[0][0] must be 0, not 1)
        if (grid[0][0] == 0) {
            q.push({0, 0});
            solve(mxlen, vis, grid, q, len, 0, 0);
        }
        
        return (mxlen == INT_MAX) ? -1 : mxlen;
    }
};
