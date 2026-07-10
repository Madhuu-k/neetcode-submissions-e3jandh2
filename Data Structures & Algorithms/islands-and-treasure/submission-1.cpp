class Solution {
public:
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    void islandsAndTreasure(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        queue<pair<int, int>> q;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] == 0) q.push({i, j});
            }
        }

        while(!q.empty()){
            int size = q.size();
            while(size--){
                auto[r, c] = q.front();
                q.pop();

                for(int k = 0; k < 4; k++){
                    int nr = r + dr[k];
                    int nc = c + dc[k];

                    if(nr >= 0&& nc >= 0 && nr < rows && nc < cols && grid[nr][nc] == 2147483647){
                        grid[nr][nc] = 1 + grid[r][c];
                        q.push({nr, nc});
                    }
                }
            }
        }
    }
};
