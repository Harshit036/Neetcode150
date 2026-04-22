class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dist(m, vector<int>(n, 1e9));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({grid[0][0], 0, 0});
        dist[0][0] = grid[0][0];
        vector<int> drxn[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while(!pq.empty()){
            vector<int> v = pq.top();
            pq.pop();
            int r = v[1];
            int c = v[2];
            int distPar = v[0];
            for(int i = 0; i < 4; i++){
                int nr = r + drxn[i][0];
                int nc = c + drxn[i][1];
                if(nr < 0 || nc < 0 || nr == m || nc == n) continue;
                int newDist = max(distPar, grid[nr][nc]);
                if(dist[nr][nc] > newDist){
                    dist[nr][nc] = newDist;
                    pq.push({newDist, nr, nc});
                }
            }
        }
        return dist[m-1][n-1];
    }
};
