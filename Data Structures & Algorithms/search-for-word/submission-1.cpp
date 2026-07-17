class Solution {
public:
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    bool dfs(vector<vector<bool>>& visited, vector<vector<char>>& board, string word, int r, int c, int idx){
        int rows = board.size();
        int cols = board[0].size();

        if(r < 0 || c < 0 || r >= rows || c >= cols) return false;
        if(visited[r][c]) return false;
        if(board[r][c] != word[idx]) return false;
        if(idx == word.size() - 1) return true;

        visited[r][c] = true;

        for(int k = 0; k < 4; k++){
            int nr = r + dr[k];
            int nc = c + dc[k];

            if(dfs(visited, board, word, nr, nc, idx + 1)) return true;
        }

        visited[r][c] = false;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(dfs(visited, board, word, i, j, 0)) return true;
            }
        }
        return false;
    }
};
