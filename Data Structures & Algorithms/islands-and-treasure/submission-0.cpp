class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0) q.push({i, j});
            }
        }
        int drx[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int i = 0; i < 4; i++){
                int nr = r + drx[i][0];
                int nc = c + drx[i][1];
                if(nr < 0 || nc < 0 || nr == m || nc == n || grid[nr][nc] == -1) continue;
                if(grid[nr][nc] > 1 + grid[r][c]){
                    q.push({nr, nc});
                    grid[nr][nc] = 1 + grid[r][c];
                }
            }
        }
        return;
    }
};
