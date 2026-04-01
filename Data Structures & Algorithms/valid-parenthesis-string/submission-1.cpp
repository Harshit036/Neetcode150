class Solution {
public:
    bool dfs(int index, int total, string s, vector<vector<int>> &dp){
        if(total < 0) return false;
        if(index == s.size()){
            // cout << total << "\n";
            return (total == 0);
        }
        if(dp[index][total] != -1) return dp[index][total];

        if(s[index] == '('){
            if(dfs(index+1, total+1, s, dp)) return dp[index][total+1] = true;
        } else if(s[index] == ')'){
            if(dfs(index+1, total-1, s, dp)) return dp[index][total-1] = true;
        } else {
            if(dfs(index+1, total, s, dp)) return dp[index][total] = true;
            if(dfs(index+1, total+1, s, dp)) return dp[index][total+1] = true;
            if(dfs(index+1, total-1, s, dp)) return dp[index][total-1] = true;
        }
        return dp[index][total] = false;
    }
    bool checkValidString(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        bool ans = dfs(0, 0, s, dp);
        return ans;
    }
};
