class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for(int i = 0; i < n; i++) dp[i][i] = 1;
        for(int i = 0; i < n-1; i++){
            if(s[i] == s[i+1]) dp[i][i+1] = 1;
        }
        for(int d = 2; d < n; d++){
            for(int i = 0; i < n - d; i++){
                int j = i + d;
                if(s[i] == s[j] && dp[i+1][j-1]){
                    dp[i][j] = 1;
                }
            }
        }
        int count = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(dp[i][j]) count++;
            }
        }
        return count;
    }
};
