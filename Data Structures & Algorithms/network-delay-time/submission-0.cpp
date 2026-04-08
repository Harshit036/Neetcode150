class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n+1);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; 
        vector<int> dist(n+1, 1e9);
        for(auto it : times){
            adj[it[0]].push_back({it[1], it[2]});
        }
        pq.push({0, k});
        dist[k] = 0;
        while(!pq.empty()){
            auto v = pq.top();
            pq.pop();
            int node = v.second;
            int distPar = v.first;
            for(auto it : adj[node]){
                if(dist[it.first] > distPar + it.second){
                    dist[it.first] = distPar + it.second;
                    pq.push({dist[it.first], it.first});
                }
            }
        }
        int maxi = 0;
        for(int i = 1; i <= n; i++){
            if(dist[i] == 1e9) return -1;
            maxi = max(maxi, dist[i]);
        }
        return maxi;
    }
};
