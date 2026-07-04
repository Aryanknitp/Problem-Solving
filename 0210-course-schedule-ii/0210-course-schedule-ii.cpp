class Solution {
public:
    bool solve(int node, const vector<vector<int>>& adj, vector<bool>& vis,
               vector<bool>& pvis, stack<int>& st) {
        vis[node] = true;
        pvis[node] = true;

        for (auto neighbor : adj[node]) {
            if (!vis[neighbor]) {
                if (solve(neighbor, adj, vis, pvis, st)) {
                    return true;
                }
            } else if (pvis[neighbor]) {
                return true;
            }
        }

        pvis[node] = false;
        st.push(node);
        return false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<bool> vis(numCourses, false);
        vector<bool> pvis(numCourses, false);

        for (auto it : prerequisites) {
            adj[it[1]].push_back(it[0]);
        }

        stack<int> st;

        for (int i = 0; i < numCourses; i++) {
            if (!vis[i]) {
                if (solve(i, adj, vis, pvis, st)) {
                    return {};
                }
            }
        }

        vector<int> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        return ans;
    }
};
