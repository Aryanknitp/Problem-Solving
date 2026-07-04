class Solution {
public:
    bool solve(int node, const vector<vector<int>>& adj, vector<bool>& visited,
               vector<bool>& pathVisited) {
        visited[node] = true;
        pathVisited[node] = true;

        for (auto neighbor : adj[node]) {
            if (!visited[neighbor]) {
                if (solve(neighbor, adj, visited, pathVisited)) {
                    return true;
                }
            } else if (pathVisited[neighbor]) {
                return true;
            }
        }

        pathVisited[node] = false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        // vector<vector<int>>p;
        // int n = p.size();
        vector<vector<int>> adj(numCourses);
        for (auto it : prerequisites) {
            adj[it[1]].push_back(it[0]);
            //   adj[it[1]].push_back(it[0]);
        }
        vector<bool> vis(numCourses, false);
        vector<bool> pathvis(numCourses, false);
          for (int i = 0; i < numCourses; i++) {
            if (!vis[i]) {
                if (solve(i, adj, vis, pathvis)) {
                    return false; 
                }
            }
        }
        return true;
    }
};