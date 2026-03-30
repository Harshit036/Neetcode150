class Solution {
public:
    int func(int i, int j, vector<vector<int>> &grid){
        int drx[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        grid[i][j] = 2;
        int ans = 1;
        for(int k = 0; k < 4; k++){
            int nr = i + drx[k][0];
            int nc = j + drx[k][1];
            if(nr < 0 || nc < 0 || nr == grid.size() || nc == grid[0].size() || grid[nr][nc] != 1) continue;
            ans += func(nr, nc, grid);
        }
        return ans;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int maxi = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    int ans = func(i, j, grid);
                    maxi = max(maxi, ans);
                }
            }
        }
        return maxi;
    }
};
