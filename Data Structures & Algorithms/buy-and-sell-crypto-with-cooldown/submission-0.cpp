class Solution {
public:
    int func(int index, int buy, vector<int> &prices, vector<vector<int>> &dp){
        if(index >= prices.size()) return 0;
        if(dp[index][buy] != -1) return dp[index][buy];
        int nottake = func(index+1, buy, prices, dp);
        int take = 0;
        if(buy){
            take = -prices[index] + func(index+1, !buy, prices, dp);
        } else {
            take = prices[index] + func(index+2, !buy, prices, dp);
        }
        return dp[index][buy] = max(take, nottake);
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int> (2, -1));
        int ans = func(0, 1, prices, dp);
        return ans;
    }
};
