class TrieNode {
public:
    TrieNode* children[26] = {nullptr};
    string word = "";
};

class Solution {
private:
    void insert(TrieNode* root, const string& word) {
        TrieNode* curr = root;
        for (char ch : word) {
            int idx = ch - 'a';
            if (!curr->children[idx]) {
                curr->children[idx] = new TrieNode();
            }
            curr = curr->children[idx];
        }
        curr->word = word;
    }

    void dfs(vector<vector<char>>& board, int r, int c, TrieNode* curr, vector<string>& result) {
        char ch = board[r][c];
        int idx = ch - 'a';
        
        if (!curr->children[idx]) return;
        
        curr = curr->children[idx];
        if (!curr->word.empty()) {
            result.push_back(curr->word);
            curr->word = ""; 
        }

        board[r][c] = '#';

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            
            if (nr >= 0 && nr < board.size() && nc >= 0 && nc < board[0].size() && board[nr][nc] != '#') {
                dfs(board, nr, nc, curr, result);
            }
        }

        board[r][c] = ch;
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();
        for (const string& word : words) {
            insert(root, word);
        }

        vector<string> result;
        int rows = board.size();
        int cols = board[0].size();

        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                dfs(board, r, c, root, result);
            }
        }

        return result;
    }
};
