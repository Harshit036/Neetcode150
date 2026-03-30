class Solution {
public:
    int drx[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    void func(int i, int j, vector<vector<char>>& grid, vector<vector<int>> &vis){
        vis[i][j] = 1;
        for(int k = 0; k < 4; k++){
            int nr = i + drx[k][0];
            int nc = j + drx[k][1];
            if(nr < 0 || nc < 0 || nr == grid.size() || nc == grid[0].size() || vis[nr][nc] || grid[nr][nc] == '0') continue;
            func(nr, nc, grid, vis);
        }
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        int ans = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    ans++;
                    func(i, j, grid, vis);
                }
            }
        }
        return ans;
    }
};
