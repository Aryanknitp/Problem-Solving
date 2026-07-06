#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        int MOD = 1e9 + 7;
        vector<vector<int>> dp_score(n, vector<int>(n, -1));
        vector<vector<int>> dp_paths(n, vector<int>(n, 0));

        dp_score[n - 1][n - 1] = 0;
        dp_paths[n - 1][n - 1] = 1;

        int dr[] = {0, 1, 1};
        int dc[] = {1, 0, 1};

        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {

                if (board[i][j] == 'X' || (i == n - 1 && j == n - 1)) {
                    continue;
                }

                int max_score = -1;
                int path_count = 0;

                for (int d = 0; d < 3; d++) {
                    int ni = i + dr[d];
                    int nj = j + dc[d];

                    if (ni < n && nj < n && dp_score[ni][nj] != -1) {
                        if (dp_score[ni][nj] > max_score) {
                            max_score = dp_score[ni][nj];
                            path_count = dp_paths[ni][nj];
                        } else if (dp_score[ni][nj] == max_score) {
                            path_count = (path_count + (dp_paths[ni][nj])%MOD) % MOD;
                        }
                    }
                }

                if (max_score != -1) {
                    int current_val =
                        (board[i][j] == 'E') ? 0 : (board[i][j] - '0');
                    dp_score[i][j] = max_score + current_val;
                    dp_paths[i][j] = path_count;
                }
            }
        }

        if (dp_score[0][0] == -1) {
            return {0, 0};
        }

        return {dp_score[0][0], dp_paths[0][0]};
    }
};
