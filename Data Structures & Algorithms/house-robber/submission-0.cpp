class Solution {
public:
    int func(int index, vector<int> &nums){
        if(index < 0) return 0;

        int take = nums[index] + func(index-2, nums);
        int nottake = func(index-1, nums);

        return max(take, nottake);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);
        for(int i = 0; i < n; i++){
            int take = nums[i], nottake = 0;
            if(i-2 >= 0)
                take = nums[i] + dp[i-2];
            if(i-1 >= 0)
                nottake = dp[i-1];
            dp[i] = max(take, nottake);
        }
        return dp[n-1];
    }
};
