class Solution {
public:
    int func(int index, int target, vector<int> &nums, vector<vector<int>> &dp){
        if(target == 0) return 1;
        if(index == nums.size()) return 0;
        if(dp[index][target] != -1) return dp[index][target];
        int left = 0;
        if(target >= nums[index]){
            left = func(0, target - nums[index], nums, dp);
        }
        int right = func(index+1, target, nums, dp);
        return dp[index][target] = left+right;
    }
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(target+1, -1));
        return func(0, target, nums, dp);
    }
};