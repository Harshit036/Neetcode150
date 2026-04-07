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
        vector<vector<int>> dp(n+1, vector<int>(5001, 0));
        for(auto it : nums) sum += it;
        if(sum%2) return false;
        int target = sum/2;
        for(int index = n-1; index >= 0; index--){
            for(int tar = 0; tar <= target; tar++){
                if(tar == 0) {
                    dp[index][tar] = 1;
                    continue;
                }
                bool take = false;
                if(tar - nums[index] >= 0){
                    take = dp[index+1][tar - nums[index]];
                }
                bool nottake = dp[index+1][tar];
                dp[index][tar] = take | nottake;
            }
        }
        return dp[0][target];
    }
};
