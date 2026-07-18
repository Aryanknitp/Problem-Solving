class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {

        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));

        priority_queue<
            pair<int, pair<int,int>>,
            vector<pair<int, pair<int,int>>>,
            greater<pair<int, pair<int,int>>>
        > pq;

        dist[0][0] = 0;
        pq.push({0, {0, 0}});

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        while (!pq.empty()) {

            auto cur = pq.top();
            pq.pop();

            int effort = cur.first;
            int x = cur.second.first;
            int y = cur.second.second;

            if (x == n - 1 && y == m - 1)
                return effort;

            if (effort > dist[x][y])
                continue;

            for (int k = 0; k < 4; k++) {

                int nx = x + dr[k];
                int ny = y + dc[k];

                if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                    continue;

                int newEffort = max(
                    effort,
                    abs(heights[nx][ny] - heights[x][y])
                );

                if (newEffort < dist[nx][ny]) {

                    dist[nx][ny] = newEffort;

                    pq.push({newEffort, {nx, ny}});
                }
            }
        }

        return 0;
    }
};