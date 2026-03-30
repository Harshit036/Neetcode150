class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 2) q.push({i, j});
            }
        }
        int drx[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int minutes = -1;
        while(!q.empty()){
            int sz = q.size();
            for(int i = 1; i <= sz; i++){
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                for(int k = 0; k < 4; k++){
                    int nr = r + drx[k][0];
                    int nc = c + drx[k][1];
                    if(nr < 0 || nc < 0 || nr == m || nc == n || grid[nr][nc] != 1) continue;
                    grid[nr][nc] = 2;
                    q.push({nr, nc});
                }
            }
            minutes++;
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1) return -1;
            }
        }
        return minutes == -1 ? 0 : minutes;
    }
};
