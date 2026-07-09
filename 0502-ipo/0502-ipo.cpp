class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int, int>> projects(n);
        
        for (int i = 0; i < n; ++i) {
            projects[i] = {capital[i], profits[i]};
        }
        
        sort(projects.begin(), projects.end());
        
        priority_queue<int> maxProfitHp;
        int idx = 0;
        
        for (int i = 0; i < k; ++i) {
            while (idx < n && projects[idx].first <= w) {
                maxProfitHp.push(projects[idx].second);
                idx++;
            }
            
            if (maxProfitHp.empty()) {
                break;
            }
            
            w += maxProfitHp.top();
            maxProfitHp.pop();
        }
        
        return w;
    }
};
