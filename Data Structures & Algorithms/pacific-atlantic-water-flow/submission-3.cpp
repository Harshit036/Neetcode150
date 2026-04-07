class Solution {
public:
    int drx[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    void dfs1(int r, int c, vector<vector<int>> &hts, vector<vector<int>> &vis){
        vis[r][c] = 1;
        for(int k = 0; k < 4; k++){
            int nr = r + drx[k][0];
            int nc = c + drx[k][1];
            if(nr < 0 || nc < 0 || nr == hts.size() || nc == hts[0].size() || vis[nr][nc]) continue;
            if(hts[nr][nc] >= hts[r][c]){
                dfs1(nr, nc, hts, vis);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& hts) {
        int m = hts.size();
        int n = hts[0].size();
        vector<vector<int>> vis1(m, vector<int>(n, 0));
        vector<vector<int>> vis2(m, vector<int>(n, 0));

        // pacific
        for(int i = 0; i < n; i++){
            if(!vis1[0][i]) dfs1(0, i, hts, vis1);
        }
        for(int i = 0; i < m; i++){
            if(!vis1[i][0]) dfs1(i, 0, hts, vis1);
        }
        for(int i = 0; i < n; i++){
            if(!vis2[m-1][i]) dfs1(m-1, i, hts, vis2);
        }
        for(int i = 0; i < m; i++){
            if(!vis2[i][n-1]) dfs1(i, n-1, hts, vis2);
        }

        vector<vector<int>> ans;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(vis1[i][j] && vis2[i][j]) ans.push_back({i, j});
            }
        }
        return ans;
    }
};
