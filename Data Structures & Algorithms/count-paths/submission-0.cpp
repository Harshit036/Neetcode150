class Solution {
public:
    int dfs(int i, int j, int m, int n, vector<vector<int>> &dp){
        if(i == m && j == n) return 1;
        if(i > m || j > n) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = dfs(i+1, j, m, n, dp) + dfs(i, j+1, m, n, dp);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        int ans = dfs(1, 1, m, n, dp);
        return ans;
    }
};
