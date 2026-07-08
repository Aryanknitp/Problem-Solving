class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        int target = n * n;
        
        queue<pair<int, int>> q;
        vector<bool> visited(target + 1, false);
        
        q.push({1, 0});
        visited[1] = true;
        
        while (!q.empty()) {
            auto [curr, moves] = q.front();
            q.pop();
            
            if (curr == target) {
                return moves;
            }
            
            for (int dice = 1; dice <= 6; ++dice) {
                int nextSquare = curr + dice;
                if (nextSquare > target) break;
                
                int r = n - 1 - (nextSquare - 1) / n;
                int c = (nextSquare - 1) % n;
                
                if ((n - 1 - r) % 2 != 0) {
                    c = n - 1 - c;
                }
                
                int final = (board[r][c] != -1) ? board[r][c] : nextSquare;
                
                if (!visited[final]) {
                    visited[final] = true;
                    q.push({final, moves + 1});
                }
            }
        }
        
        return -1;
    }
};
