class Solution {
public:
    bool func(int index, int target, vector<int> &nums, vector<vector<int>> &dp){
        if(target == 0) return true;
        if(target < 0 || index == nums.size()) return false;
        if(dp[index][target] != -1) return dp[index][target];
        bool take = func(index+1, target-nums[index], nums, dp);
        if(take) return dp[index][target] = true;
        bool nottake = func(index+1, target, nums, dp);
        return dp[index][target] = nottake;
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(5001, -1));
        for(auto it : nums) sum += it;
        if(sum%2) return false;
        int target = sum/2;
        bool ans = func(0, target, nums, dp);
        return ans;
    }
};
