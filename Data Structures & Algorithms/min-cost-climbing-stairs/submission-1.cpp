class Solution {
public:
    int func(int index, vector<int> &cost, vector<int> &dp){
        if(index >= cost.size()) return 0;
        if(dp[index] != -1) return dp[index];
        int ans = cost[index] + min(func(index+1, cost, dp), func(index+2, cost, dp));
        return dp[index] = ans;
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n, -1);
        int ans1 = func(0, cost, dp);
        int ans2 = func(1, cost, dp);

        return min(ans1, ans2);
    }
};
