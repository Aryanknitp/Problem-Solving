class Solution {
public:
    bool solve(vector<vector<int>>& grid, int health,
               queue<pair<int, int>>& que) {
        int m = grid.size(), n = grid[0].size();
        vector<int> dr = {0, -1, 0, +1};
        vector<int> dc = {-1, 0, +1, 0};

        vector<vector<int>> max_health(m, vector<int>(n, -1));

        int start_health = health - grid[0][0];
        if (start_health < 1)
            return false;
        max_health[0][0] = start_health;

        while (!que.empty()) {
            auto [f, s] = que.front();
            que.pop();

            int current_health = max_health[f][s];

            if (f == m - 1 && s == n - 1 && current_health >= 1)
                return true;

            for (int i = 0; i < 4; i++) {
                int nr = f + dr[i];
                int nc = s + dc[i];
                if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                    int next_health = current_health - grid[nr][nc];
                    if (next_health >= 1 && next_health > max_health[nr][nc]) {
                        max_health[nr][nc] = next_health;
                        que.push({nr, nc});
                    }
                }
            }
        }
        return false;
    }
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        queue<pair<int, int>> q;
        q.push({0, 0});
        return solve(grid, health, q);
    }
};
