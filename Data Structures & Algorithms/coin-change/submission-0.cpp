class Solution {
public:
    int func(int index, int amount, vector<int> &coins, vector<vector<int>> &dp){
        if(amount == 0) return 0;
        if(index == coins.size()) return 1e9;
        if(dp[index][amount] != -1) return dp[index][amount];
        int take = 1e9;
        if(amount-coins[index] >= 0)
            take = 1 + func(index, amount-coins[index], coins, dp);
        int nottake = func(index+1, amount, coins, dp);
        return dp[index][amount] = min(take, nottake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int> (amount+2, -1));
        int ans = func(0, amount, coins, dp);
        if(ans == 1e9) return -1;
        return ans;
    }
};
