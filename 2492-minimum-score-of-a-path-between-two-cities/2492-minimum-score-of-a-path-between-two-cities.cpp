class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        queue<int> q;
        int ans = INT_MAX;
        vector<int> vis(n+1, 0);
        vector<vector<pair<int, int>>> adjlist(n+1);
        for (auto it : roads) {
            adjlist[it[0]].push_back({it[1], it[2]});
            adjlist[it[1]].push_back({it[0], it[2]});
        }
        q.push(1);
        vis[1] = 1;
        while (!q.empty()) {
            int f = q.front();
            q.pop();
            for (auto& [v, w] : adjlist[f]) {
                ans = min(w, ans);
                if (vis[v] == 0) {
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
        return ans;
    }
};
