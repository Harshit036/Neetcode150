class Solution {
public:
    int dfs(int index, int n, vector<int> &nums, vector<int> &dp){
        if(index >= n) return 0;
        if(dp[index] != -1) return dp[index];
        int take = nums[index] + dfs(index+2, n, nums, dp);
        int nottake = dfs(index+1, n, nums, dp);

        return dp[index] = max(take, nottake);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        vector<int> dp1(n, -1);
        vector<int> dp2(n, -1);
        int ans1 = dfs(0, n-1, nums, dp1);
        int ans2 = dfs(1, n, nums, dp2);
        return max(ans1, ans2);
    }
};
