class Solution {
public:
    int func(int index, int amount, vector<int> &coins, vector<vector<int>> &dp){
        if(amount == 0) return 1;
        if(amount < 0 || index == coins.size()) return 0;
        if(dp[index][amount] != -1) return dp[index][amount];
        return dp[index][amount] = func(index, amount-coins[index], coins, dp) + func(index+1, amount, coins, dp);
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int> (amount+1, -1));
        int ans = func(0, amount, coins, dp);
        return ans;
    }
};
