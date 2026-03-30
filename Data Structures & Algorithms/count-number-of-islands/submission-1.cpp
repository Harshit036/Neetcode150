class Solution {
public:
    int drx[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    void func(int i, int j, vector<vector<char>>& grid){
        grid[i][j] = '2';
        for(int k = 0; k < 4; k++){
            int nr = i + drx[k][0];
            int nc = j + drx[k][1];
            if(nr < 0 || nc < 0 || nr == grid.size() || nc == grid[0].size() || grid[nr][nc] != '1') continue;
            func(nr, nc, grid);
        }
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1'){
                    ans++;
                    func(i, j, grid);
                }
            }
        }
        return ans;
    }
};
