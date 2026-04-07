class Solution {
public:
    int func(int index, int prev, vector<int> &nums, vector<vector<int>> &dp){
        if(index == nums.size()+1) return 0;
        if(dp[index][prev] != -1) return dp[index][prev];
        int nottake = func(index+1, prev, nums, dp);
        if(prev == 0 || nums[index-1] > nums[prev-1]){
            return dp[index][prev] = max(nottake, 1 + func(index+1, index, nums, dp));
        }
        return dp[index][prev] = nottake;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+2, vector<int>(n+2, -1));
        int ans = func(1, 0, nums, dp);
        return ans;
    }
};
