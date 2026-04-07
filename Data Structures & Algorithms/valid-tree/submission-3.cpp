class Solution {
public:
    bool dfs(int node, vector<vector<int>> &adj, vector<int> &color){
        color[node] = 1;
        for(auto it : adj[node]){
            if(color[it] == 0){
                if(dfs(it, adj, color)) return true;
            } else if(color[it] == 2) return true;
        }
        color[node] = 2;
        return false;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<int> color(n, 0);
        vector<vector<int>> adj(n);
        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            if(u == v) return false;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(color[i] == 0){
                cnt++;
                if(dfs(i, adj, color)) return false;
            }
            if(cnt > 1) return false;
        }
        return true;
    }
};
