class Solution {
public:
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& ocean, int r, int c){
        ocean[r][c] = true;
        int rows = heights.size();
        int cols = heights[0].size();

        for(int k = 0; k < 4; k++){
            int nr = r + dr[k];
            int nc = c + dc[k];
            if(nr >= 0 && nc >= 0 && nr < rows && nc < cols && !ocean[nr][nc] && heights[nr][nc] >= heights[r][c]) dfs(heights, ocean, nr, nc);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();

        vector<vector<bool>> pacific(rows, vector<bool>(cols, false));
        vector<vector<bool>> atlantic(rows, vector<bool>(cols, false));

        for(int i = 0; i < rows; i++) dfs(heights, pacific, i, 0);
        for(int j = 0; j < cols; j++) dfs(heights, pacific, 0, j);

        for(int i = 0; i < rows; i++) dfs(heights, atlantic, i, cols - 1);
        for(int j = 0; j < cols; j++) dfs(heights, atlantic, rows - 1, j);

        vector<vector<int>> result;

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(pacific[i][j] && atlantic[i][j]) result.push_back({i, j});
            }
        }

        return result;
    }
};
